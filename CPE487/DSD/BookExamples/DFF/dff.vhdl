library IEEE;
use IEEE.std_logic_1164.all;
--entity code
entity d_ff is
    port ( D, clk : in std_logic;
           Q :      out std_logic);
end d_ff;
-- circuit arch
architecture my_d_ff of d_ff is
begin
    dff: process(clk)
    begin
        if (rising_edge(clk)) then
            Q <= D;
        end if;
    end process dff;
end my_d_ff;
