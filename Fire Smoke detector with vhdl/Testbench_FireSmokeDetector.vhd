--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:13:39 11/30/2024
-- Design Name:   
-- Module Name:   /home/ise/firesmokedetector/Testbench_FireSmokeDetector.vhd
-- Project Name:  firesmokedetector
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: FireSmokeDetector
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY Testbench_FireSmokeDetector IS
END Testbench_FireSmokeDetector;
 
ARCHITECTURE behavior OF Testbench_FireSmokeDetector IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT FireSmokeDetector
    PORT(
         clk : IN  std_logic;
         rst : IN  std_logic;
         timed : IN  std_logic;
         temp_data : IN  std_logic_vector(23 downto 0);
         smoke_data : IN  std_logic_vector(23 downto 0);
         water : OUT  std_logic;
         start_timer : OUT  std_logic;
         fire_alert : INOUT  std_logic_vector(2 downto 0);
         smoke_alert : INOUT  std_logic_vector(2 downto 0);
         critical_alert : INOUT  std_logic;
         send_fire_truck : INOUT  std_logic_vector(2 downto 0);
         siren_alarm : INOUT  std_logic;
         emergency_notification : INOUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';
   signal timed : std_logic := '0';
   signal temp_data : std_logic_vector(23 downto 0) := (others => '0');
   signal smoke_data : std_logic_vector(23 downto 0) := (others => '0');

	--BiDirs
   signal fire_alert : std_logic_vector(2 downto 0);
   signal smoke_alert : std_logic_vector(2 downto 0);
   signal critical_alert : std_logic;
   signal send_fire_truck : std_logic_vector(2 downto 0);
   signal siren_alarm : std_logic;
   signal emergency_notification : std_logic;

 	--Outputs
   signal water : std_logic;
   signal start_timer : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: FireSmokeDetector PORT MAP (
          clk => clk,
          rst => rst,
          timed => timed,
          temp_data => temp_data,
          smoke_data => smoke_data,
          water => water,
          start_timer => start_timer,
          fire_alert => fire_alert,
          smoke_alert => smoke_alert,
          critical_alert => critical_alert,
          send_fire_truck => send_fire_truck,
          siren_alarm => siren_alarm,
          emergency_notification => emergency_notification
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
  stim_proc: process
    begin
        -- Reset the system
        rst <= '1';
        wait for CLK_PERIOD;
        rst <= '0';
		  -- Test Case 1: No alerts, normal operation
        temp_data <= X"000000";  -- Low temperatures
        smoke_data <= X"000000"; -- Low smoke levels
        wait for 5 * CLK_PERIOD;
		   -- Test Case 2: Fire in Zone 3
        temp_data <= X"3C0000";  -- Zone 3 above temperature threshold
        smoke_data <= X"000000"; -- No smoke
        wait for 5 * CLK_PERIOD;
		  -- Test Case 3: Smoke in Zone 2
        temp_data <= X"000000";  -- Normal temperatures
        smoke_data <= X"003000"; -- Zone 2 above smoke threshold
        wait for 5 * CLK_PERIOD;

        -- Test Case 4: Fire and smoke in Zone 1 (critical alert)
        temp_data <= X"00003C";  -- Zone 1 above temperature threshold
        smoke_data <= X"000030"; -- Zone 1 above smoke threshold
        wait for 5 * CLK_PERIOD;
		  
		  -- Test Case 5: Return to normal
        temp_data <= X"000000";
        smoke_data <= X"000000";
        wait for 5 * CLK_PERIOD;

        -- Stop simulation
        wait;
    end process;

END;
