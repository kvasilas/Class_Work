library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity DFF is
	Port ( 	D : in STD_LOGIC;
				clk : STD_LOGIC;
				Q : out STD_LOGIC;
				Qb : out STD_LOGIC);
end DFF;

architecture Behavioral of DFF is

begin
ffpr: process is
	begin
		wait until clk' event and clk ='1';
		Q <= D after 10 ns;
		Qb<= not D after 10 ns;
end process;

end Behavioral;

