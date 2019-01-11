library ieee;
use ieee.std_logic_1164.all;

entity half_adder is
port (
    a : in std_logic;
    b : in std_logic;
    --
    s : out std_logic;
    c : out std_logic);
end;
architecture behavioral of half_adder is
begin
    s <= a xor b;
    c <= a and b;

end;
