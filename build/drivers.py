import os
from os.path import basename
from compile_file import compile_file
from get_driver_files import get_driver_files
from ensure import ensure_drivers_outdir

base = basename(os.getcwd())

if (base != "build"):
    os.chdir("build")

ensure_drivers_outdir()

driver_files = get_driver_files()

for driver_file in driver_files:
    compile_file(driver_file, "drivers")

print("Done !")
