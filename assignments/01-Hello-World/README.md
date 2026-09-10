## Identifying Effective Strategies for Learning

**1. Choose a moment in your educational career (it could be an assignment or a full course) where learning went really well. What strategies did you employ that worked particularly well (e.g., working with others, trying work on your own before asking a friend, going to office hours)?**  

I think learning went well for me in both Software Design and Software Systems, whcih had similar assignment structure to this class. I tried doing the homeworks by myself first, sometimes together with a friend. And if we couldn't figure out any part of the problem together, we would go to office hours, or in this new day and age, maybe Claude as well. Doing my assignments this way helped me learn well.

**2. Similar to (1), which sorts of strategies have led to either less effective learning or less enjoyment of the learning experience. Feel free to describe a few examples of what doesn’t work for you.**

I think a lot of sitting at the desk drilling a problem with no outside help or perspectives can be very frustrating. I enjoy being able to discuss a problem with someone else, and the defeated feeling can lead me to lose motivation of finishing my work. 

**3. As this course is foundational for many aspects of computer science, the problems in this class can be easily solved with modern AI systems (e.g., ChatGPT, Gemini, etc.). One of my foundational assumptions is the process of grappling with a problem helps you internalize the important concepts, gives you more insight into how the tools you are learning can be applied in other contexts, helps you more realistically assess your own abilities, and helps you learn to better communicate your knowledge to others. Particular methods of using AI (e.g., prompting the AI to provide answers to questions and thoughtlessly copying the answers) are unlikely to achieve the learning goals articulated previously. Do you agree with this framing? How are you thinking about AI tools with respect to this course?**

I agree with the framing. I will refrain from using AI to do any part of the problem solving or my assignments. In limited cases, I might ask it to review my solutions after I've come up with one that I deem the best that I can think of.

**4. What strategies will you use in this course to be successful? With respect to AI, what principles or strategies will you use during this course.**

Since I'm doing this class in C++, I will use a lot of C++ resources to get me up to speed with the language. I have taken SoftSys before so I have C knowledge which will hopefully help with the transition. With regards to AI, I won't contract out any thinking on my part to AI tools. 

**5. What do you think of some of the proposed activities for the oral quizzes? Are these activities ones that would give you helpful feedback as to how you are performing with respect to the course material? Would you add or subtract any of the proposed activities?**

I love the oral quiz format. I think it will be cool.

**6. How can the teaching team support you?**

Good C++ support? (I don't expect much since we did put this on ourselves...)

## Hello World!

**1. What features do you like about C++?**

I don't really know. Compared to C, it has a lot to love, namely not having to manually allocate amount of memory for each variable. But compared to Python? Not so sure.

**2. Are there things you were expecting to find that you haven’t?**

Not really. 

**3. What questions do you have?**

Why is it so hard?

**4. Try using the debugger (see the Getting Set with Kotlin page) for some very basic information on the debugger. Do you have experience using interactive debuggers like this one? Were you able to successfully launch the debugger?**

I've used gdb for C before, and I assume this is similar.

## Porting Code

I ported over the TicTacToe code from back in the SoftDes days, which was originally written in Python, and I have included it in this assignment folder as well. It was definitely less headache to port over than some other assignments as it used no external libraries, which was really nice. At the same time, the TicTacToe assignment didn't use any high-level Python methods, leaving the port over to C++ rather straightforward. Figuring out the CMake linking and what not for the test took a little bit. I'm pretty sure this solution I have currently isn't the most elegant or even the most correct. CMake is even more confusing than C++, and the former is already confusing enough.

## Implementing Meeting Scheduler

As the first algorithm is a straight up O(n^2) brute-force, the run time discrepancy between the two algorithms will grow at a slightly lower than exponential scale? The sorting is only O(n log n), and given that I'm doing this in C++, it must be next to zero already, right?

