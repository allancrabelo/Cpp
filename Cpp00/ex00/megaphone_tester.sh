#!/bin/bash
# ************************************************************************** #
#                                                                            #
#                           MEGAPHONE TESTER (C++98)                         #
#                                                                            #
# ************************************************************************** #

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# ------------------------ COMPILATION -------------------------------------- #
echo -e "${YELLOW}Compiling megaphone.cpp...${NC}"
cc -Wall -Wextra -Werror -std=c++98 -pedantic -x c++ megaphone.cpp -lstdc++ -o megaphone
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Compilation failed.${NC}"
    exit 1
fi
echo -e "${GREEN}✅ Compilation successful!${NC}\n"

# ------------------------ TEST CASES --------------------------------------- #
inputs=(
    ""  # no arguments
	"shhhhh... I think the students are asleep..."
    "Damnit ' ! ' 'Sorry students, I thought this thing was off.'"
)

expected=(
    "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
	"SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
    "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
)

# ------------------------ RUN TESTS ---------------------------------------- #
pass=0
fail=0
total=${#inputs[@]}

for i in "${!inputs[@]}"; do
    input="${inputs[$i]}"
    expected="${expected[$i]}"

    if [ -z "$input" ]; then
        result=$(./megaphone)
    else
        # Use eval to correctly interpret quoted args (" " etc.)
        result=$(eval ./megaphone $input)
    fi

    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}✅ PASSED${NC} | Input: ${input}"
        ((pass++))
    else
        echo -e "${RED}❌ FAILED${NC} | Input: ${input}"
        echo "  Expected: '${expected}'"
        echo "  Got:      '${result}'"
        ((fail++))
    fi
done

# ------------------------ SUMMARY ------------------------------------------ #
echo
echo -e "${YELLOW}Summary:${NC}  $pass passed, $fail failed (total $total)"
if [ $fail -eq 0 ]; then
    echo -e "${GREEN}🎉 All tests passed!${NC}"
else
    echo -e "${RED}💥 Some tests failed.${NC}"
fi
