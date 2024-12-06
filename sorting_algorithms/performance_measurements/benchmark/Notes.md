# Notes on Benchmarking Setup

To ensure reliable measurements with Google Benchmark, you can configure your CPU by fixing the frequencies.
1. **If needed, disable Turbo Boost using**

`echo "1" | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo`.

3. **Start by setting the CPU governor to `performance` using**

`sudo cpupower frequency-set -g performance`, 

3. **fix the frequency range to your desired value (e.g., `2.20GHz`) with** 

`sudo cpupower frequency-set --min 2.20GHz --max 2.20GHz`.

Verify the settings using: 

`cpupower frequency-info` 

to confirm the governor, frequency range, and Turbo Boost status. 

After benchmarking, revert changes by restoring the default governor (`ondemand`) with 

`sudo cpupower frequency-set -g ondemand`, 

resetting the frequency range to hardware limits (`2.20GHz - 4.95GHz`) using 

`sudo cpupower frequency-set --min 2.20GHz --max 4.95GHz`, 

and re-enabling Turbo Boost with 

`echo "0" | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo`. 

Verify the reverted settings with `cpupower frequency-info` to ensure the governor 
is `ondemand` and frequencies are dynamically adjustable. 

Use this command to monitor the current CPU frequencies in real-time:

`watch -n 1 "cat /proc/cpuinfo | grep 'MHz'"`
