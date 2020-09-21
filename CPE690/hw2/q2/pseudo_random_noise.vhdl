-- question 2 (3) pseaudo random code generator
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity noise_gen is
    Port ( clk : in STD_LOGIC;
        reset : in STD_LOGIC;
        data : buffer STD_LOGIC_VECTOR (3 downto 0));
end noise_gen;

architecture Behavioral of noise_gen is
    component four_bit_shift_register
    port( 
        sin : in std_logic;
        clk : in std_logic;
        Q : buffer std_logic_vector (3 downto 0);
        Qb : out std_logic);
    end component;
    signal s1, s2 : std_logic;
begin
    s1 <= data(2) xor data(3);
    s2 <= s1 or reset;
    shift_reg : four_bit_shift_register port map(s2, clk, data, open);
end Behavioral;

