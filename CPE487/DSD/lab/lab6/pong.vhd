library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity pong is
 Port ( clk_50MHz : in STD_LOGIC; -- system clock
 VGA_red : out STD_LOGIC_VECTOR (2 downto 0); -- VGA outputs
 VGA_green : out STD_LOGIC_VECTOR (2 downto 0);
 VGA_blue : out STD_LOGIC_VECTOR (1 downto 0);
 VGA_hsync : out STD_LOGIC;
 VGA_vsync : out STD_LOGIC;
 ADC_CS : out STD_LOGIC; -- ADC signals
 ADC_SCLK : out STD_LOGIC;
 ADC_SDATA1 : in STD_LOGIC;
 ADC_SDATA2 : in STD_LOGIC;
 btn0 : in STD_LOGIC); -- button to initiate serve
end pong;
architecture Behavioral of pong is
signal ck_25: STD_LOGIC := '0'; -- 25 MHz clock to VGA sync module
 -- internal signals to connect modules
signal S_red, S_green, S_blue: STD_LOGIC;
signal S_vsync: STD_LOGIC;
signal S_pixel_row, S_pixel_col: STD_LOGIC_VECTOR (9 downto 0);
signal batpos: STD_LOGIC_VECTOR (9 downto 0);
signal serial_clk, sample_clk: STD_LOGIC;
signal adout: STD_LOGIC_VECTOR (11 downto 0);
signal count: STD_LOGIC_VECTOR (9 downto 0); -- counter to generate ADC clocks
component adc_if is
 Port ( SCK: in STD_LOGIC;
 SDATA1 : in STD_LOGIC;
 SDATA2 : in STD_LOGIC;
 CS: in STD_LOGIC;
 data_1 : out STD_LOGIC_VECTOR(11 downto 0);
 data_2 : out STD_LOGIC_VECTOR(11 downto 0));
end component;
component bat_n_ball is
 Port ( v_sync : in STD_LOGIC;
 pixel_row : in STD_LOGIC_VECTOR(9 downto 0);
 pixel_col : in STD_LOGIC_VECTOR(9 downto 0);
 bat_x : in STD_LOGIC_VECTOR (9 downto 0);
 serve : in STD_LOGIC;
 red : out STD_LOGIC;
 green : out STD_LOGIC;
 blue : out STD_LOGIC);
end component;
component vga_sync is
 Port ( clock_25MHz : in STD_LOGIC;
 red : in STD_LOGIC;
 green : in STD_LOGIC;
 blue : in STD_LOGIC;
 red_out : out STD_LOGIC;
 green_out : out STD_LOGIC;
 blue_out : out STD_LOGIC;
 hsync : out STD_LOGIC;
 vsync : out STD_LOGIC;
 pixel_row : out STD_LOGIC_VECTOR (9 downto 0);
 pixel_col : out STD_LOGIC_VECTOR (9 downto 0));
end component;
begin
 -- Process to generate clock signals
ckp: process
begin
wait until rising_edge(clk_50MHz);
ck_25 <= not ck_25; -- 25MHz clock for VGA modules
count <= count+1; -- counter to generate ADC timing signals
end process;
serial_clk <= not count(4); -- 1.5 MHz serial clock for ADC
ADC_SCLK <= serial_clk;
sample_clk <= count(9); -- sampling clock is low for 16 SCLKs
ADC_CS <= sample_clk;
 -- Multiplies ADC output (0-4095) by 5/32 to give bat position (0-640)
batpos <= ('0'& adout(11 downto 3)) + adout(11 downto 5);
 -- set least significant bits of VGA video to '0'
VGA_red(1 downto 0) <= "00";
VGA_green(1 downto 0) <= "00";
VGA_blue(0) <= '0';
adc: adc_if port map ( -- instantiate ADC serial to parallel interface
SCK => serial_clk,
CS => sample_clk,
SDATA1 => ADC_SDATA1,
SDATA2 => ADC_SDATA2,
data_1 => OPEN,
data_2 => adout );
add_bb: bat_n_ball port map( --instantiate bat and ball component
v_sync => S_vsync,
pixel_row => S_pixel_row,
pixel_col => S_pixel_col,
bat_x => batpos,
serve => btn0,
red => S_red,
green=> S_green,
blue => S_blue);
vga_driver: vga_sync port map( --instantiate vga_sync component
clock_25MHz => ck_25,
red => S_red,
green => S_green,
blue => S_blue,
red_out => VGA_red(2),
green_out => VGA_green(2),
blue_out => VGA_blue(1),
pixel_row => S_pixel_row,
pixel_col => S_pixel_col,
hsync => VGA_hsync,
vsync => S_vsync);
VGA_vsync <= S_vsync; --connect output vsync
end Behavioral;
