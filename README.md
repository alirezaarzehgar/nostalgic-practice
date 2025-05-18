# Opening an old diary about C
This repository could be a code snippet on Gist. But I love it!
Writing unit tests for fewer than five functions seems foolish, but I missed CUnit!
I developed this piece of dream because, as a Go developer and current DevOps, I love C.
I love playing with heap memory.

Maybe I will never return to System Software Engineering, the C programming language, and Linux Kernel investigations, but
remember, I love low-level stuff like never before, my dear machine codes.

Anyway, let me discuss this code. You can write some basic mathematical expressions, and my diary will tell you whether they are correct or wrong.
You can check pda_test.c for test cases. Everybody knows code without tests is just smart trash.
Compile the code using make, my favorite command. It will create pda and tests for you, and running them is totally up to you.

How does the result look?

```bash
$ cat testdata/exp.txt | ./pda 
✅ 0: 1+2
✅ 1: 1+2/4
✅ 2: (1+2/4)+(3^1)
✅ 3: (1+3)/(1*(3+1))
✅ 4: ((1+3)/(1*(3+1)))
❌ 5: (((1+3)/(1*(((3+1)))
❌ 6: ((1+3)/(1*(3+1))))
❌ 7: (1+3)/(1*(3+1)))
❌ 8: (1+3
✅ 9: (1+2)
✅ 10: [a+b/c]+[1+[a*b]]
❌ 11: [a+3]*[b+[c]]
✅ 12: [[a+3]*[b+[c]]]
❌ 13: [a+3]*[b+[c]
❌ 14: [a+3]*[b+[c]]]
✅ 15: [a+{2+c}]
✅ 16: [a+{2+(a+v)}]/((((1+c/{a^5}))))
❌ 17: [a+{2+c)]
✅ 18: ([a+{2+(a+v)}]/((((1+c/{a^5})))))
❌ 19: ([a+{2+(a+v)}]/((((1+c/{a^5}))))}
```

How does tests look?

```bash
$ ./tests 


     CUnit - A unit testing framework for C - Version 2.1-3
     http://cunit.sourceforge.net/


Suite: stack
  Test: test for push and pop functions ...passed
  Test: count push current location ...passed
  Test: check grammar ...passed

Run Summary:    Type  Total    Ran Passed Failed Inactive
              suites      1      1    n/a      0        0
               tests      3      3      3      0        0
             asserts     54     54     54      0      n/a

Elapsed time =    0.000 seconds
```

I hope this repository makes you nostalgic!
