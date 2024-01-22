#include &lt;stdio.h&gt;
int fr[3];
void main()
{
void display();
int i, j, page[12] = {2,3,2,1,5,2,4,5,3,2,5,2};
int flag1 = 0, flag2 = 0, pf = 0, frsize = 3, top = 0;
for (i =0; i &lt;3; i++)
{
fr[i]=-1;
}
for (j =0; j&lt; 12; j++)
{
flag1 =0;
flag2 =0;
for (i =0; i&lt; 12; i++)
{
if (fr[i] == page[j])
{
flag1 =1;
flag2 =1;
break;
}
}
if (flag1 ==0)
{
for (i=0; i &lt; frsize; i++)
{
if (fr[i] ==-1)
{
fr[i] = page[j];
flag2 =1;
break;
}
}
}
if (flag2 ==0)
{
fr[top] = page[j];
top++;
pf++;
if (top &gt;= frsize)
top=0;
}
display();
}

printf(&quot;Number of page faults : %d&quot;, pf + frsize);
}
void display() {
int i;
printf(&quot;\n&quot;);
for (i =0; i&lt;3; i++)
printf(&quot;%d\t&quot;, fr[i]);
}