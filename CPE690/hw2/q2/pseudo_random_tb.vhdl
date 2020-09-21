library ieee;
use ieee.std_logic_1164.all;

entity pseudo_random_tb is
end pseudo_random_tb;

architecture behavior of pseudo_random_tb is
    component noise_gen is 
        port( 
            sin : in std_logic;
            clk : in std_logic;
            Q : buffer std_logic_vector (3 downto 0);
            Qb : out std_logic);
    end component;
    signal s1, s2 : std_logic;
begin
    uut: noise_gen PORT MAP (
        clk => clk,
        reset => reset,
        data => data,
        Q => Q,
        Qb => Qb
    );
    
    reset_waveform: process is
    begin
        reset <= '1', '0' after 200 ns;
        wait for 700 ns;
    end process;
    
    clk_waveform: process is
    begin
        clk <= '0', '1' after 15 ns;
        wait for 30 ns;
    end process;
end;