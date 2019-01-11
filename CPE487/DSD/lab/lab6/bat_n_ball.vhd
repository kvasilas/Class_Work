library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity bat_n_ball is
 Port ( v_sync : in STD_LOGIC;
 pixel_row : in STD_LOGIC_VECTOR(9 downto 0);
 pixel_col : in STD_LOGIC_VECTOR(9 downto 0);
 bat_x : in STD_LOGIC_VECTOR (9 downto 0); -- current bat x position
 serve: in STD_LOGIC; -- initiates serve
 red : out STD_LOGIC;
 green : out STD_LOGIC;
 blue : out STD_LOGIC);
end bat_n_ball;
architecture Behavioral of bat_n_ball is
constant bsize: integer:=8; -- ball size in pixels
constant bat_w: integer:=20; -- bat width in pixels
constant bat_h: integer:=3; -- bat height in pixels
-- distance ball moves each frame
constant ball_speed: STD_LOGIC_VECTOR (9 downto 0) := CONV_STD_LOGIC_VECTOR (6,10);
signal ball_on: STD_LOGIC; -- indicates whether ball is at current pixel position
signal bat_on: STD_LOGIC; -- indicates whether bat at over current pixel position
signal game_on: STD_LOGIC := '0'; -- indicates whether ball is in play
-- current ball position - intitialized to center of screen
signal ball_x: STD_LOGIC_VECTOR(9 downto 0):= CONV_STD_LOGIC_VECTOR(320,10);
signal ball_y: STD_LOGIC_VECTOR(9 downto 0):= CONV_STD_LOGIC_VECTOR(240,10);
-- bat vertical position
constant bat_y: STD_LOGIC_VECTOR(9 downto 0):= CONV_STD_LOGIC_VECTOR(400,10);
-- current ball motion - initialized to (+ ball_speed) pixels/frame in both X and Y directions
signal ball_x_motion, ball_y_motion: STD_LOGIC_VECTOR(9 downto 0):= ball_speed;
begin
red <= not bat_on; -- color setup for red ball and cyan bat on white background
green <= not ball_on;
blue <= not ball_on;
 -- process to draw round ball
 -- set ball_on if current pixel address is covered by ball position
balldraw: process (ball_x, ball_y, pixel_row, pixel_col) is
variable vx, vy: STD_LOGIC_VECTOR (9 downto 0);
begin
if pixel_col <= ball_x then -- vx = |ball_x - pixel_col|
vx := ball_x - pixel_col; else
vx := pixel_col - ball_x;
end if;
if pixel_row <= ball_y then -- vy = |ball_y - pixel_row|
vy := ball_y - pixel_row; else
vy := pixel_row - ball_y;
end if;
if((vx*vx) + (vy*vy)) < (bsize*bsize) then -- test if radial distance < bsize
ball_on <= game_on; else
ball_on <= '0';
end if;
end process;
-- process to draw bat
-- set bat_on if current pixel address is covered by bat position
batdraw: process (bat_x, pixel_row, pixel_col) is
variable vx, vy: STD_LOGIC_VECTOR (9 downto 0);
begin
if ((pixel_col >= bat_x - bat_w) or (bat_x <= bat_w)) and
pixel_col <= bat_x + bat_w and
pixel_row >= bat_y - bat_h and
pixel_row <= bat_y + bat_h then bat_on <= '1';
else bat_on <= '0';
end if;
end process;
-- process to move ball once every frame (i.e. once every vsync pulse)
mball: process
variable temp: STD_LOGIC_VECTOR (10 downto 0);
begin
wait until rising_edge(v_sync);
if serve = '1' and game_on = '0' then -- test for new serve
game_on <= '1';
ball_y_motion <= (not ball_speed) + 1; -- set vspeed to (- ball_speed) pixels
elsif ball_y <= bsize then -- bounce off top wall
ball_y_motion <= ball_speed; -- set vspeed to (+ ball_speed) pixels
elsif ball_y + bsize >= 480 then -- if ball meets bottom wall
ball_y_motion <= (not ball_speed) + 1; -- set vspeed to (- ball_speed) pixels
game_on <= '0'; -- and make ball disappear
end if;
-- allow for bounce off left or right of screen
if ball_x + bsize >= 640 then -- bounce off right wall
ball_x_motion <= (not ball_speed) +1; -- set hspeed to (- ball_speed) pixels
elsif ball_x <= bsize then -- bounce off left wall
ball_x_motion <= ball_speed; -- set hspeed to (+ ball_speed) pixels
end if;
-- allow for bounce off bat
if (ball_x + bsize/2) >= (bat_x - bat_w) and
(ball_x - bsize/2) <= (bat_x + bat_w) and
(ball_y + bsize/2) >= (bat_y - bat_h) and
(ball_y - bsize/2) <= (bat_y + bat_h) then
ball_y_motion <= (not ball_speed) + 1; -- set vspeed to (- ball_speed) pixels
end if;
 -- compute next ball vertical position
 -- variable temp adds one more bit to calculation to fix unsigned underflow problems
 -- when ball_y is close to zero and ball_y_motion is negative
temp := ('0' & ball_y) + (ball_y_motion(9) & ball_y_motion);
if game_on = '0' then ball_y <= CONV_STD_LOGIC_VECTOR(440,10);
elsif temp(10) = '1' then ball_y <= (others=>'0');
else ball_y <= temp(9 downto 0);
end if;
 -- compute next ball horizontal position
 -- variable temp adds one more bit to calculation to fix unsigned underflow problems
 -- when ball_x is close to zero and ball_x_motion is negative
temp := ('0' & ball_x) + (ball_x_motion(9) & ball_x_motion);
if temp(10) = '1' then ball_x <= (others=>'0');
else ball_x <= temp(9 downto 0);
end if;
end process;
end Behavioral;
