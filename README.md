Description:

This project is a C-based simulation program that calculates, optimizes, and distributes multiple sources of renewable energy—solar, wind, hydro, and steam. The program utilizes pointers, structures, and dynamic memory allocation to store and manage energy production data in real time. Through a menu-driven interface, users can:

Input energy production parameters (e.g., area, efficiency, flow rate).
Calculate and store the resulting energy values.
Optimize energy utilization and simulate consumption.
Distribute the stored renewable energy equally among different micro energy sources.
Key Features:

Structured Approach: Uses a custom struct ModelEnergi to store relevant parameters (e.g., luasPermukaanSelSurya, intensitasSinarMatahari, produksiMatahari).
Pointer Utilization: Demonstrates pointer-based array handling (ptrSimulasiEnergi) for dynamic storage of simulation results.
Dynamic Memory Allocation: Implements malloc() and free() to manage memory usage for up to MAX_SIMULASI simulations.
Menu-Driven: Provides a user-friendly interface to select actions (e.g., “1. Produksi Energi Matahari”, “2. Produksi Energi Hidro”, “3. Keluar dari Program”, dsb.).
Error Handling: Checks for invalid inputs and ensures data is available before proceeding with distribution or optimization steps.
