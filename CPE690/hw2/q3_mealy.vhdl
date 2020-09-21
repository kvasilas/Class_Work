-- Kirk Vasilas
-- Homework 2 
-- Question 3 Mealy state machine 
-- Sequence = 1011

library ieee;
use ieee.std_logic_1164.all;

entity mealy_fsm is
    port(data_in,clk: std_logic;
    data_out: out std_logic);
end entity mealy_fsm;

architecture mealy of mealy_fsm is
    type state is (s0, s1, s2, s3);
    signal curr_state, next_state: state;

begin
    clk_proc: process(reset,clk)
    begin
        if(reset ='1')then
            curr_state <= s0;
        elsif(clk'event and clk = '1')then
            curr_state <= next_state;
        end if;
    end process;

    state_decider: process(data_in, curr_state)
    begin
        case curr_state is
            when s0 =>
                data_out <= '0';
                if(data_in ='1') then next_state <= s1;
                else next_state <= s0;
                end if;
            when s1 =>
                data_out <= '0';
                if(data_in ='0') then next_state <= s2;
                else next_state <= s1;
                end if;
            when s2 =>
                data_out <= '0';
                if(data_in ='1') then next_state <= s3;
                else next_state <= s0;
                end if;
            when s3 =>
                if(data_in ='1') then 
                    data_out <= '1';
                    next_state <= s1;
                else 
                    data_out <= '0';    
                    next_state <= s2;
                end if;
            end case;
    end process;
end architecture;