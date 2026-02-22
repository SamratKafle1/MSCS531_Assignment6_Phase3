# Final Power/Performance Summary (Comparative Estimator)

This folder contains the final consolidated metrics used for Deliverable 4.

## Files
- `phase3_metrics_summary.csv` - Extracted gem5 performance metrics from Phase 3 runs
- `final_power_estimates.csv` - Comparative normalized power/energy estimates added for final analysis

## Notes
- Performance metrics (`simSeconds`, `simInsts`, `numCycles`, `IPC`, `CPI`, `L1D miss rate`) come directly from gem5 `stats.txt`.
- Power/energy values are **normalized comparative estimates** used for configuration ranking (not silicon-calibrated absolute watt values).
- The estimator was used to compare tradeoffs across:
  - frequency (1GHz vs 500MHz)
  - cache configuration (base vs L1D32k)

## Derived metrics
- `energy_est_norm = power_est_norm × simSeconds`
- `epi_est_norm = energy_est_norm / simInsts`
- `edp_est_norm = energy_est_norm × simSeconds`
