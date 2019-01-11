library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity vga_sync is
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
end vga_sync;
architecture Behavioral of vga_sync is
signal h_cnt, v_cnt: STD_LOGIC_VECTOR (9 DOWNTO 0);
begin
sync_pr: process
variable video_on: STD_LOGIC;
begin
wait until rising_edge(clock_25MHz);
-- Generate Horizontal Timing Signals for Video Signal
-- h_cnt counts pixels across line (800 total = 640 active + extras for sync and blanking)
-- Active picture for 0 <= h_cnt <= 639
-- Hsync for 659 <= h_cnt <= 755
if h_cnt >= 799 then
h_cnt <= "0000000000"; else
h_cnt <= h_cnt+1;
end if;
if (h_cnt >= 659) and (h_cnt <= 755) then
hsync <= '0'; else
hsync <= '1';
end if;
-- Generate Vertical Timing Signals for Video Signal
-- v_cnt counts lines down screen (525 total = 480 active + extras for sync and blanking)
-- Active picture for 0 <= v_cnt <= 479
-- Vsync for 493 <= h_cnt <= 494
if (v_cnt >= 524) and (h_cnt = 699) then
v_cnt <= "0000000000";
elsif h_cnt = 699 then
v_cnt <= v_cnt+1;
end if;
if (v_cnt >= 493) and (v_cnt <= 494) then
vsync <= '0'; else
vsync <= '1';
end if;
-- Generate Video Signals and Pixel Address
if (h_cnt <= 639) and (v_cnt <= 479) then
video_on := '1'; else
video_on := '0';
end if;
pixel_col <= h_cnt;
pixel_row <= v_cnt;
-- Register video to clock edge and suppress video during blanking and sync periods
red_out <= red and video_on;

green_out <= green and video_on;
blue_out <= blue and video_on;
end process;
end Behavioral;
