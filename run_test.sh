#! /bin/sh

# immediate exit in case of any failure
set -e

declare -a files=(
    "mazestack.cpp"
    "mazequeue.cpp"
    "eval.cpp"
)

function cleanup {
    make -s clean
    for f in "${files[@]}"; do
        rm -f "$f"
    done
}

for f in "${files[@]}"; do
    cp ../"$f" .
done


# substitute out possible main function
sed 's/[[:blank:]]*int[[:blank:]]+main(/int main__[[:blank:]]*(/g' < mazestack.cpp > TMPmazestack.cpp
mv TMPmazestack.cpp mazestack.cpp

sed 's/[[:blank:]]*int[[:blank:]]+main(/int main__[[:blank:]]*(/g' < mazequeue.cpp > TMPmazequeue.cpp
mv TMPmazequeue.cpp mazequeue.cpp

sed 's/[[:blank:]]*int[[:blank:]]+main(/int main__[[:blank:]]*(/g' < eval.cpp > TMPeval.cpp
mv TMPeval.cpp eval.cpp

# compile and test
make -s all

echo "testing mazestack.cpp"
./stack.out
echo
echo "testing mazequeue.cpp"
./queue.out
echo
echo "testing eval.cpp"
./eval.out
echo

echo "clean up ..."
cleanup
