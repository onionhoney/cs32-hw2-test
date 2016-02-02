#! /bin/sh

# immediate exit in case of any failure
set -e

declare -a files=(
    "mazestack.cpp"
    "mazequeue.cpp"
    "eval.cpp"
)

function cleanup {
    {
        for f in "${files[@]}"; do
            rm "$f"
        done
        rm testMap.out;
    } >> /dev/null 2>&1
    exit $1
}

for f in "${files[@]}"; do
    cp ../"$f" .
done


# substitute out possible main function
sed 's/\s*int\s+main(/int main__(/g' < mazestack.cpp > TMPmazestack.cpp
mv TMPmazestack.cpp mazestack.cpp

sed 's/\s*int\s+main(/int main__(/g' < mazequeue.cpp > TMPmazequeue.cpp
mv TMPmazequeue.cpp mazequeue.cpp

sed 's/\s*int\s+main(/int main__(/g' < eval.cpp > TMPeval.cpp
mv TMPeval.cpp eval.cpp

# compile and test
make -s all

./stack.out
echo
./queue.out
echo
./eval.out

make -s clean

cleanup 0
