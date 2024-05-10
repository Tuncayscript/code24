from platform import system
from os import environ, getcwd, system as execute

include = Dir("antlrInclude")

CCFLAGS = []
osname = system().lower()
if osname in ["linux", "darwin"]:
    CCFLAGS = ["-O3"]
if osname == "windows":
    CCFLAGS = ["/std:c++17", "/EHsc"]

env = Environment(ENV={"PATH": environ["PATH"]}, CPPPATH=include)


# env.Command would be better but sandboxes the python runtime
execute("antlr4 antlr/CodeLexer.g4 -Dlanguage=Cpp -o ./gen")
execute("antlr4 antlr/CodeParser.g4 -Dlanguage=Cpp -lib ./gen -o ./gen")
execute("antlr4 antlr/Common.g4 -Dlanguage=Cpp -lib ./gen -o ./gen")
execute("antlr4 antlr/Preprocessor.g4 -Dlanguage=Cpp -lib ./gen -o ./gen")

generated_files = env.Glob("./gen/*.cpp")

env.Program(
    "code24",
    ["src/main.cpp"] + generated_files,
    LIBS="antlr4-runtime",
    CPPPATH=env["CPPPATH"],
    CCFLAGS=CCFLAGS,
)
