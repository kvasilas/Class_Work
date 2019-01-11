library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ball is
 Port ( v_sync : in STD_LOGIC;
 pixel_row : in STD_LOGIC_VECTOR(9 downto 0);
 pixel_col : in STD_LOGIC_VECTOR(9 downto 0);
 red : out STD_LOGIC;
 green : out STD_LOGIC;
 blue : out STD_LOGIC);
end ball;

architecture Behavioral of ball is
constant size: integer:=10;
signal ball_on: STD_LOGIC; -- indicates whether ball is over current pixel position
-- current ball position - intitialized to center of screen
signal ball_x: STD_LOGIC_VECTOR(9 downto 0):= CONV_STD_LOGIC_VECTOR(320,10);
signal ball_y: STD_LOGIC_VECTOR(9 downto 0):= CONV_STD_LOGIC_VECTOR(240,10);

-- current ball motion - initialized to +4 pixels/frame
signal ball_y_motion: STD_LOGIC_VECTOR(9 downto 0):= "0000000100";
begin
red <= not ball_on; -- color setup for red ball on white background
green <= '1';
blue <= not ball_on;
-- process to draw ball current pixel address is covered by ball position
bdraw: process (ball_x, ball_y, pixel_row, pixel_col) is
begin
    if (conv_interger(pixel_col)-conv_interger(ball_x))*
    (conv_interger(pixel_col)-conv_interger(ball_x))+
    (conv_interger(pixel_col)-conv_interger(ball_x))*
    (conv_interger(pixel_col)-conv_interger(ball_x))<
    (size*size)
    ball_on <= '1'; else
        ball_on <= '0';
end if;
end process;
-- process to move ball once every frame (i.e. once every vsync pulse)
mball: process
begin
wait until rising_edge(v_sync);
-- allow for bounce off top or bottom of screen
if ball_y + size >= 480 then
ball_y_motion <= "1111111100"; -- -4 pixels
elsif ball_y <= size then
ball_y_motion <= "0000000100"; -- +4 pixels
end if;
ball_y <= ball_y + ball_y_motion; -- compute next ball position
end process;
end Behavioral;
