import os
from os.path import basename
from compile_file import compile_file
from get_all_files import get_all_files
from ensure import ensure_all_outdir

base = basename(os.getcwd())

if (base != "build"):
    os.chdir("build")

ensure_all_outdir()

all_files = get_all_files()

cmd = ["gcc"]
for file in all_files:
    cmd.append(str.replace(file, "\\", "/"))
cmd.append("-o")
cmd.append("../dist/mobilita")

print("Compiling all files ...")
status = os.system(" ".join(cmd))
if (status == 0):
    print("\033[38;5;46mCompilation successful!\033[0m")
else:
    print("\033[38;5;196mFailed to compile. There was an error.\033[0m")
