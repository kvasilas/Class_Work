use std.textio.all; -- Imports the standard textio package.
-- Defines a design entity, without any ports.
entity hello_world is
end hello_world;
architecture behaviour of hello_world is
begin
process
variable l : line;
--variable k: line;
begin
write (l, String'("Hello world!"));
writeline (output, l);
--write (k, String'("Suck it"));
--writeline (output, k);
wait;
end process;
end behaviour;
