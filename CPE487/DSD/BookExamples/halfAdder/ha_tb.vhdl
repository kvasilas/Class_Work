library ieee;
use ieee.std_logic_1164.all;

entity half_adder_testbench is
end half_adder_testbench;
architecture behavior of half_adder_testbench is
    component half_adder is
        port (
            a : in std_logic;
            b : in std_logic;
            s : out std_logic;
            c : out std_logic);
    end component;
    signal input : std_logic_vector(1 downto 0);
    signal output : std_logic_vector(1 downto 0);
begin
    uut: half_adder port map (
        a => input(0),
        b => input(1),
        s => output(0),
        c => output(1)
    );
    stim_proc: process
        begin
            input <= "00"; wait for 10 ns; assert output = "00" report "0+0+0 failed";
            input <= "01"; wait for 10 ns; assert output = "01" report "0+0+1 failed";
            input <= "10"; wait for 10 ns; assert output = "01" report "0+1+0 failed";
            input <= "11"; wait for 10 ns; assert output = "10" report "0+1+1 failed";
            report "half adder testbench finished";
            wait;
        end process;
end;
