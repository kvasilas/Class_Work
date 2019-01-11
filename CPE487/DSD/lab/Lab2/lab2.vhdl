library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity hexcount is
 Port ( clk_50MHz : in STD_LOGIC;
 anode : out STD_LOGIC_VECTOR (3 downto 0);
 seg : out STD_LOGIC_VECTOR (6 downto 0));
end hexcount;

architecture Behavioral of hexcount is
component counter is
Port ( clk : in STD_LOGIC;
 count : out STD_LOGIC_VECTOR (3 downto 0)
 mpx: out STD_LOGIC_VECTOR (1 downto 0));
end component;

component leddec is
Port ( dig : in STD_LOGIC_VECTOR (1 downto 0);
data : in STD_LOGIC_VECTOR (3 downto 0);
anode: out STD_LOGIC_VECTOR (3 downto 0);
 seg : out STD_LOGIC_VECTOR (6 downto 0));
end component;
signal S: STD_LOGIC_VECTOR (3 downto 0);

begin
C1: counter port map (clk=>clk_50MHz, count=>S);
L1: leddec port map (dig=>"00", data=>S, anode=>anode, seg=>seg);
display <= S (3 downto 0) when md = "00" else
    S (7 downto 4) when md = "01" else
    S (11 downto 8) when md = "10" else
    S (15 downto 12) when md = "11" else
end Behavioral;
