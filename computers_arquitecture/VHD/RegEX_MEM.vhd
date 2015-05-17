library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity RegEX_MEM is
    Port ( CLK : in  STD_LOGIC;
           DATA1 : in  STD_LOGIC_VECTOR (15 downto 0);
			  DATA2 : in  STD_LOGIC_VECTOR (15 downto 0);
			  DATA3 : in  STD_LOGIC_VECTOR (15 downto 0);																																
			  DATA4 : in  STD_LOGIC_VECTOR (4 downto 0);			  
			  DATA5 : in  STD_LOGIC_VECTOR (1 downto 0);
			  DATA6 : in  STD_LOGIC_VECTOR (1 downto 0);
			  
           SAL1 : out  STD_LOGIC_VECTOR (15 downto 0);
			  SAL2 : out  STD_LOGIC_VECTOR (15 downto 0);			  
			  SAL3 : out  STD_LOGIC_VECTOR (15 downto 0);
			  SAL4 : out  STD_LOGIC_VECTOR (4 downto 0);			  
			  SAL5 : out  STD_LOGIC_VECTOR (1 downto 0);
			  SAL6 : out  STD_LOGIC_VECTOR (1 downto 0));
end RegEX_MEM;

architecture Behavioral of RegEX_MEM is
signal Q1int: std_logic_vector(15 downto 0):= (others => '0');
signal Q2int: std_logic_vector(15 downto 0):= (others => '0');
signal Q3int: std_logic_vector(15 downto 0):= (others => '0');
signal Q4int: std_logic_vector(4 downto 0):= (others => '0');
signal Q5int: std_logic_vector(1 downto 0):= (others => '0');
signal Q6int: std_logic_vector(1 downto 0):= (others => '0');
begin

	process (CLK)
		begin

		if falling_edge(CLK) then
			Q1int <= DATA1;
			Q2int <= DATA2;
			Q3int <= DATA3;
			Q4int <= DATA4;
			Q5int <= DATA5;
			Q6int <= DATA6;
		end if;

	end process;
SAL1 <= Q1int;
SAL2 <= Q2int;
SAL3 <= Q3int;
SAL4 <= Q4int;
SAL5 <= Q5int;
SAL6 <= Q6int;

end Behavioral;