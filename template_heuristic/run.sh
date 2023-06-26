cp /dev/null ./res.txt
g++ main.cpp -o main
for file in $(ls -1 ./in/*.txt); do
	./main < $file > out.txt
	cargo run --release --bin vis $file ./out.txt > ./out2.txt
	cat ./out2.txt | ruby help.rb
done
echo "Done! Score:"
cat res.txt
