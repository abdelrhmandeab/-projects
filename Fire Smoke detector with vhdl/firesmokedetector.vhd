----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:45:32 11/29/2024 
-- Design Name: 
-- Module Name:    firesmokedetector - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity FireSmokeDetector is

Port (
        clk                : in  STD_LOGIC;
        rst                : in  STD_LOGIC;
		timed			   : in  std_logic;
        temp_data          : in  STD_LOGIC_VECTOR(23 downto 0); -- 8 bits per zone (3 zones)
        smoke_data         : in  STD_LOGIC_VECTOR(23 downto 0); -- 8 bits per zone (3 zones)
		water 			   : out std_logic;
		start_timer		   : out std_logic;
		fire_alert         : inout STD_LOGIC_VECTOR(2 downto 0);  -- Fire alert for each zone
        smoke_alert        : inout STD_LOGIC_VECTOR(2 downto 0);  -- Smoke alert for each zone
        critical_alert     : inout STD_LOGIC;                     -- Global critical alert
        send_fire_truck    : inout STD_LOGIC_VECTOR(2 downto 0);   -- Fire truck priority signal for each zone
        siren_alarm        : inout STD_LOGIC;                     -- Siren alarm activation
		emergency_notification : inout STD_LOGIC                  -- Emergency services notification
    );
end FireSmokeDetector;

	architecture Behavioral of FireSmokeDetector is
    -- Constants for thresholds
    constant TEMP_THRESHOLD : STD_LOGIC_VECTOR(7 downto 0) := "00111100"; -- 60°C
    constant SMOKE_THRESHOLD: STD_LOGIC_VECTOR(7 downto 0) := "00110000"; -- Smoke level 48
	 -- FSM states
    type state_type is ( READ_SENSORS, CHECK_ZONES, EVALUATE_CONDITIONS,CRITICAL_SITUATION);
    signal pr_state, nxt_state : state_type;
	 	    -- Internal signals
    signal alert_log                   : STD_LOGIC_VECTOR(2 downto 0); -- Log state per zone
	
	begin
    -- Sequential block for state transitions
	    seq: process (clk)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                pr_state <= READ_SENSORS;
            else
                pr_state <= nxt_state;
            end if;
        end if;
    end process;
	 	 	-- Combinational logic block
    comb: process (pr_state, temp_data, timed, smoke_data, alert_log,fire_alert,critical_alert,smoke_alert,siren_alarm,emergency_notification)
    begin
        -- Default outputs
		  		  case pr_state is
            

            -- Read sensors
        when READ_SENSORS =>
		fire_alert <= (others => '0');
        smoke_alert <= (others => '0');
		water<='0';
		start_timer<='0';
        critical_alert <= '0';
	    send_fire_truck <= (others => '0');
        siren_alarm <= '0';  -- No siren by default
		emergency_notification <= '0';  -- No notification by default
        nxt_state <= CHECK_ZONES;


			            -- Check thresholds for each zone
			when CHECK_ZONES =>
				for i in 0 to 2 loop
                    if temp_data((i+1)*8-1 downto i*8) >= TEMP_THRESHOLD then
                        fire_alert(i) <= '1';
                    else
                        fire_alert(i) <= '0';
                    end if;
						  					     if smoke_data((i+1)*8-1 downto i*8) >= SMOKE_THRESHOLD then
                        smoke_alert(i) <= '1';
                     else
                        smoke_alert(i) <= '0';
                    end if;
                end loop;
				if ((fire_alert or smoke_alert)= "000") then                 nxt_state <= READ_SENSORS;
				else
                nxt_state <= EVALUATE_CONDITIONS;
				end if;
					 
					 					 -- Evaluate alert conditions
            when EVALUATE_CONDITIONS =>
			water<='1';
                for i in 0 to 2 loop
					if (fire_alert(i) = '1' And smoke_alert(i) = '1') then
						critical_alert  <= '1';
					end if;


                end loop;
				if critical_alert = '1' then                nxt_state <=critical_situation ;
				else start_timer<='1';
				end if;
				if timed='1' then 
				for i in 0 to 2 loop
                    if temp_data((i+1)*8-1 downto i*8) >= TEMP_THRESHOLD then
                        fire_alert(i) <= '1';
                    else
                        fire_alert(i) <= '0';
                    end if;
						  					     if smoke_data((i+1)*8-1 downto i*8) >= SMOKE_THRESHOLD then
                        smoke_alert(i) <= '1';
                    else
                        smoke_alert(i) <= '0';
                    end if;
                end loop;
				end if;

				if ((fire_alert or smoke_alert)="000") then                 nxt_state <= READ_SENSORS;
				else  nxt_state <=critical_situation ;
				end if;
					 
					             -- critical_situation  for each zone and take action for critical alert
            when critical_situation =>
              
               for i in 0 to 2 loop
						 if fire_alert(i) = '1' or smoke_alert(i) = '1' then
							  send_fire_truck(i) <= '1';
						 else
							  send_fire_truck(i) <= '0';
						 end if;
				end loop;
					                -- Trigger siren and notify emergency services if critical alert is active
                    siren_alarm <= '1';  -- Activate siren
                    emergency_notification <= '1';  -- Notify emergency services

                nxt_state <= READ_SENSORS;

            -- Default case
            when others => nxt_state <= READ_SENSORS;
       end case;
	end process;



end Behavioral;

