library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity vga_top is
 Port ( clk_50MHz : in STD_LOGIC;
 vga_red : out STD_LOGIC_VECTOR (2 downto 0);
 vga_green : out STD_LOGIC_VECTOR (2 downto 0);
 vga_blue : out STD_LOGIC_VECTOR (1 downto 0);
 vga_hsync : out STD_LOGIC;
 vga_vsync : out STD_LOGIC);
end vga_top;

architecture Behavioral of vga_top is
signal ck_25: STD_LOGIC;
-- internal signals to connect modules
signal S_red, S_green, S_blue: STD_LOGIC;
signal S_vsync: STD_LOGIC;
signal S_pixel_row, S_pixel_col: STD_LOGIC_VECTOR (9 downto 0);
component ball is
 Port ( v_sync : in STD_LOGIC;
 pixel_row : in STD_LOGIC_VECTOR(9 downto 0);
 pixel_col : in STD_LOGIC_VECTOR(9 downto 0);
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
-- Process to generate 25 MHz clock from 50 MHz system clock
ckp: process
begin
wait until rising_edge(clk_50MHz);
ck_25 <= not ck_25;
end process;
-- vga_driver only drives MSB of red, green & blue
-- so set other bits to zero
vga_red(1 downto 0) <= "00";
vga_green(1 downto 0) <= "00";
vga_blue(0) <= '0';
add_ball: ball port map( --instantiate ball component
v_sync => S_vsync,
pixel_row => S_pixel_row,
pixel_col => S_pixel_col,
red => S_red,
green=> S_green,
blue => S_blue);
vga_driver: vga_sync port map( --instantiate vga_sync component
clock_25MHz => ck_25,
red => S_red,
green => S_green,
blue => S_blue,
red_out => vga_red(2),
green_out => vga_green(2),
blue_out => vga_blue(1),
pixel_row => S_pixel_row,
pixel_col => S_pixel_col,
hsync => vga_hsync,
vsync => S_vsync);
vga_vsync <= S_vsync; --connect output vsync
end Behavioral;
