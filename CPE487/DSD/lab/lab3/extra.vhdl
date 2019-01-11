mball: process
begin
wait until rising_edge(v_sync);
-- allow for bounce off top or bottom of screen
if ball_y + size >= 480 then
ball_y_motion <= "1111111100"; -- -4 pixels
elsif ball_y <= size then
ball_y_motion <= "0000000100"; -- +4 pixels
end if;

if ball_x + size >= 640 then
ball_x_motion <= "1111111100"; -- -4 pixels
elsif ball_x <= size then
ball_x_motion <= "0000000100"; -- +4 pixels
end if;

ball_y <= ball_y + ball_y_motion; -- compute next ball position
end process;
