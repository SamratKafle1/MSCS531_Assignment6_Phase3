# MSCS531 Assignment 6 - Phase 3 (gem5 Performance + Power Prep)

This repo contains:
- `phase3_workloads/` : compute_bound + memory_bound microbenchmarks (x86 binaries + source)
- `phase3_runs/`      : per-run gem5 output dirs (stats.txt, config.ini/config.json)

gem5 was executed in SE mode using:
- CPU: TimingSimpleCPU
- Caches: --caches
- Clocks: 1GHz and 500MHz
- Instruction cap: -I 10000000 for microbenches

Note:
- `fs/` subfolders are excluded to keep repo small.
