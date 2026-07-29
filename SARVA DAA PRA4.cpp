#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
unsigned long long factIter(int num)
{
unsigned long long ans = 1;
while (num &gt; 1)
{
ans *= num;
num--;
}
return ans;
}
unsigned long long factRec(int num)
{
if (num == 0 || num == 1)
return 1;
return num * factRec(num - 1);
}
int main()
{
int n;
cout &lt;&lt; &quot;Enter a non-negative integer (e.g., 20): &quot;;
cin &gt;&gt; n;
if (n &lt; 0)
{
cout &lt;&lt; &quot;Invalid input! Please enter a non-negative
integer.&quot;;
return 0;
}
auto start = high_resolution_clock::now();
unsigned long long iterative = factIter(n);
auto stop = high_resolution_clock::now();
auto time1 = duration_cast&lt;nanoseconds&gt;(stop - start);
start = high_resolution_clock::now();
unsigned long long recursive = factRec(n);
stop = high_resolution_clock::now();
auto time2 = duration_cast&lt;nanoseconds&gt;(stop - start);
cout &lt;&lt; &quot;\n--- Results for &quot; &lt;&lt; n &lt;&lt; &quot;! ---&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;Iterative Result : &quot; &lt;&lt; iterative &lt;&lt; endl;
cout &lt;&lt; &quot;Iterative Time : &quot; &lt;&lt; time1.count() &lt;&lt; &quot; ns&quot;
&lt;&lt; endl;
cout &lt;&lt; &quot;-------------------------------&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;Recursive Result : &quot; &lt;&lt; recursive &lt;&lt; endl;
cout &lt;&lt; &quot;Recursive Time : &quot; &lt;&lt; time2.count() &lt;&lt; &quot; ns&quot;
&lt;&lt; endl;
return 0;
}
