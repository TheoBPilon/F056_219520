for i in {1..10}
do
    ./hello $i > output_$i.txt &
done
wait