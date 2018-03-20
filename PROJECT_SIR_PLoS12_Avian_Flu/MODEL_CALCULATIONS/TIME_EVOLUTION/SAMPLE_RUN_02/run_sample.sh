# Notice that reordering output variables -n 6 -v0 ... has a profound effect on the graphical output.
#../CONSTANT__CPGPLOT_REPRESENTATION_B_00_I_00_3p -P0 3 -G0 1 -G1 3 -T2 100.0 -E 1 -n 6 -v0 4 -v1 5 -v2 7 -v3 12 -v4 13 -v5 15 -G2 0 -G4 100.0 -G5 0 -G7 1000.0
# Exemple 1. S, I and V are the output variables:
## ../CONSTANT__CPGPLOT_REPRESENTATION_B_00_I_00_3p -R0 1 -P0 3 -G0 1 -G1 3 -T2 100.0 -E 1 -n 6 -v0 4 -v1 12 -v2 5 -v3 13 -v4 7 -v5 15 -G2 0 -G4 100.0 -G5 0 -G7 300000
# Exemple 2. S and I are the output variables:
../CONSTANT__CPGPLOT_REPRESENTATION_B_00_I_00_3p -R0 1 -P0 3 -G0 1 -G1 2 -T0 900 -T2 400.0 -E 1 -n 4 -v0 4 -v1 12 -v2 5 -v3 13 -v4 7 -v5 15 -G2 0 -G4 400.0 -G5 0 -G7 800.0
