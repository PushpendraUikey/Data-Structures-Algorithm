#include <iostream>
#include <sys/wait.h>
#include <bits/stdc++.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(){
    int p[2];
    char* argv[2];

    argv[0] = "wc";
    argv[1] = 0;

    pipe(p);
    if(fork()==0){
        close(0);
        dup(p[0]);
        close(p[0]);
        close(p[1]);
        exec("/bin/wc", argv);
    }else{
        close(p[0]);
        write(p[1], "hello world\n", 12);
        close(p[1]);
    }
}

// void myFunction() {
//     static std::vector<int> vec;
//     vec.push_back(vec.size()); // Adding the current size of the vector
//     std::cout << "Vector size: " << vec.size() << std::endl;
//     cout << "Vector capacity: " << vec.capacity() << endl;
// }

// int main() {
//     for (int i = 0; i < 5; ++i) {
//         myFunction();
//     }
//     return 0;
// }

    //// Test is done to check deep copy is performed in both cases assignment and push_back
    // std::vector<std::vector<int>> vec1, vec2(100000);
    // auto start = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < 1e5; ++i) {
    //     std::vector<int> vec(1000,0);
    //     vec1.push_back(std::move(vec));
    // }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // std::cout << "Time taken in pushback of vector: " << duration.count() << " microseconds." << std::endl;

    // start = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < 1e5; ++i) {
    //     std::vector<int> vec(1000,0);
    //     vec2[i] = std::move(vec);
    // }
    // end = std::chrono::high_resolution_clock::now();
    // duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // std::cout << "Time taken in = of vector: " << duration.count() << " microseconds." << std::endl;

// fork() --> along with the file descriptors, offsets are also copied.
// int main(){
//     int rc = fork();

//     if(rc == 0){
//         sleep(2);
//         write(1, "Hello ", 6);
//         exit(0);
//     }else{
//         wait(0);
//         write(1, "world\n", 6);
//         exit(0);
//     }
// }

// int x = 3;
// int main(){
//     while(x > 0){
//         int ret = fork();
//         if(ret == 0){
//             printf("x = %d\n", x);
//         }
//         else wait(NULL);
//         x--;
//     }
// }

// O_TRUNC is used to vanish the content of the given input file while keeping the file there.
// int main(){
//     int fd = open("input.txt", O_TRUNC);
//     close(fd);

// }

// int main(){
//     int a=10, b=5;
//     std::cout << a+++b << endl;
//     std::cout << "a: " << a << " b: " << b << endl;
// }

// #define p 0.03

// int main(){
//     int n=100000;
//     int cnt = n;
//     srand(time(nullptr));
//     int A=0, B=0, AB=0;

// //  A = {2,4,6}
// //  and B ={1,2,3,4}. Then, P(A)=1/2, P(B)=2/3 and P(AB)=1/3.
// //  Since P(AB)=P(A)P(B)

//     while(n-->0){
//         int val = (std::rand())%6+1;
//         if(val == 1){
//             B++;
//         }else if(val == 2){
//             A++; B++; AB++;
//         }else if(val == 3){
//             B++;
//         }else if(val==4){
//             A++; B++; AB++;
//         }else if(val == 6){
//             A++;
//         }
//     }

//     std::cout<< "P(A): " <<(double)A/cnt<< "\t\t" << "P(B): " << (double)B/cnt << "\t\t"<< (double)AB/cnt << "\n";
// }