PID=27522

# エラーテスト
./client -1 $(printf %01000d 1)
./client 0 $(printf %01000d 1)
./client 1 $(printf %01000d 1)
./client 2 $(printf %01000d 1)
./client 3 $(printf %01000d 1)
./client 4 $(printf %01000d 1)
./client 5 $(printf %01000d 1)
./client 6 $(printf %01000d 1)

# 耐久テスト
for i in `seq 1 1000`; do
    ./client $PID $(printf %01000d $i)
done

echo "Done"