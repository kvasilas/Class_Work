library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity shift_reg is
	Port ( 	sin : in STD_LOGIC;
				clk : in STD_LOGIC;
				Q0 : out STD_LOGIC;
				Q1 : out STD_LOGIC;
				Q2 : out STD_LOGIC;
				Q3 : out STD_LOGIC;
				Qb : out STD_LOGIC);
end shift_reg;

architecture RTL of shift_reg is
	component DFF 
	Port( D : in STD_LOGIC;
			clk : in STD_LOGIC;
			Q : out STD_LOGIC;
			Qb : out STD_LOGIC);
	end component;
	
	signal s1,s2,s3,s4: STD_LOGIC;

begin

	bit0 : DFF port map (clk => clk, D=>sin, Q=>s1, Qb=>open);
	bit1 : DFF port map (clk => clk, D=>s1, Q=>s2, Qb=>open);
	bit2 : DFF port map (clk => clk, D=>s2, Q=>s3, Qb=>open);
	bit3 : DFF port map (clk => clk, D=>s3, Q=>s4, Qb=>open);

	Q0<= s1 after 5 ns;
	Q1<= s2 after 5 ns;
	Q2<= s3 after 5 ns;
	Q3<= s4 after 5 ns;
	
end architecture RTL;