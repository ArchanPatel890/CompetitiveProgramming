import argparse
import os
import errno
from shutil import copyfile


parser = argparse.ArgumentParser(
    description="Creates a new CodeForces contest directory. Adds IO files and templates files.")
parser.add_argument("name", type=str, nargs="?", help="The name or number of the contest.")
parser.add_argument("nProblems", type=int, help="Number of problems in the contest.")
parser.add_argument("--official", "-off", action='store_true', help="If the contest is official.")
parser.add_argument("--practice", "-prac", action='store_true', help="If the contest is practice (default).")
parser.add_argument("--output", "-o", nargs="?", help="Output directory of contest (default practice dir)")
parser.add_argument("--prefix", nargs="?", help="Prefix for the contest submission files.")
parser.add_argument("--template", "-t", nargs="?", default="template.cpp", help="Template to use for problems.")

args = parser.parse_args()
curr_dir = os.path.dirname(__file__)
if not args.name:
    raise Exception("Requires a contest name.")

assert(1 <= args.nProblems <= 26)


# Make the Output Category dir and the contest directory.
def TryMakeDir(folder: str):
    try:
        os.makedirs(folder)
        print("Created directory: {}".format(folder))
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise e
        else:
            print("Directory: {} already exists.".format(folder))

practice_dir = os.path.join(curr_dir, "..", "Practice")
official_dir = os.path.join(curr_dir, "..", "Official")
category_dir = practice_dir

if args.official:
    category_dir = official_dir

contest_dir = None
if not args.output:
    TryMakeDir(category_dir)
    contest_dir = os.path.join(category_dir, args.name)
    TryMakeDir(contest_dir)
else:
    contest_dir = os.path.join(curr_dir, args.output)
    TryMakeDir(contest_dir)


# Create the IO Files.
input_file = os.path.join(contest_dir, "input.txt")
output_file = os.path.join(contest_dir, "output.txt")
files = [input_file, output_file]
for file in files:
    if not os.path.exists(file):
        with open(file, "w"): pass


# Open the template file for each problem.
template_file = None
if args.template:
    template_file = os.path.join(curr_dir, args.template)
print("Using template: {}".format(template_file))


# Create problem files under the contest directory.
print("Making {} problem files.".format(args.nProblems))
prefix = args.prefix if args.prefix else args.name
extension = os.path.splitext(template_file)[1]
for i in range(0, args.nProblems):
    suffix = chr(ord('A') + i)
    new_file = os.path.join(contest_dir, "".join([prefix, suffix, extension]))
    if not os.path.exists(new_file):
        copyfile(template_file, new_file)
        print("Created new problem file: {}".format(new_file))
    else:
        print("Problem file: {} already exists.".format(new_file))
