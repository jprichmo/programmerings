Lesson 1 - The Shape of Color
Background Info
Processing — the father of p5.js — is a coding environment designed for artists and musicians with little to no experience programming. if you are new to this, we’ll get you making something awesome by the end of this lesson. p5.js is the JavaScript version with the added benefit of running natively on the web. The online editor is easy to use right in the browser with nothing to install.
Helpful Links
Editor: the online p5.js editor
Reference: documentation for all things in p5.js
End Product
In this lesson, we will get to know the editor and the default code, then learn how to color shapes and lines, ending with colorful circles for you to play with. As a bonus, we’ll make some mistakes too.
Steps
Getting Started
The first thing that we need to do is log in so our code is saved automagically and can be accessed from anywhere. Lesson 0 covers getting started with sign up and log in as well as a quick tour of the editor with some tips and tricks to help you as you go.

Once you are logged in, you should see a window that looks much like this, greeting you by your username…
There are a couple __functions__ defined in the middle on the left and a preview
window on the right that looks pretty empty to me. Let’s change that. In the upper left is a play button that will run the code. Click it. 
Did anything change?
The Definition Follows Function
In the area beneath the play button, we see numbers along the left side telling us which line we are on, and those two groups of code beginning with `function` starting on lines 1 and 5, respectively.

A note on formatting: We will use __bold__ for words that have a specific meaning in programming, *italics* for names of those things in our code, as well as emphasis, and `monospaced text` for actual code and values. __Functions__ will always be written with the trailing parentheses even when just referring to the name. So *background()* can be `background(100)` and `background(200,20,200)` and the like.
The setup function
The first one called *setup()* does what it says on the tin: *sets up the scene*. This is where we put the code that needs to happen at the beginning. It will only run one time. The last thing on line 1 and the only thing on line 3 are the *curly brackets* `{` `}` (aka *braces* or *curlies*). These enclose the body of the function. Everything inside is run when the function is called.

What do you think `createCanvas(400,400)` does?
Try changing the first number to `600`. What happened?

Now we get to break something. Select all of line 2 and cut it by holding down __Control__ and pressing __X__ ( __Command+X__ on macOS) and paste it with __Ctrl+V__ ( __Cmd+V__ ) on line 4.
CONGRATULATIONS! You just created an Uncaught ReferenceError! And it highlighted the line in pink! 

The truth is, making mistakes is part of learning how to make things. So when the pink highlights come, be encouraged, because I think you can fix these kinds of mistakes. I bet you can start by fixing this one. (Hint, in this case, __Ctrl+Z__ is your friend.)

Try calling *createCanvas()* without a comma separating the __parameters__. Try calling it with just one number in the __parameter list__. Try calling it with three numbers. Every error is slightly different. Read the messages. And then undo them to get it running again.

You’ve probably figured out what *createCanvas()* does. So what do you think might happen if we commented it out — that is, made it so that the environment ignores it when run? Click anywhere in line 2 and press __Ctrl+/__ ( __Cmd+/__ ).
Notice how two slashes appear at the beginning of the line and the color changed to a faded grey. Run it and observe what happens. Then uncomment the line by placing the cursor back in line 2 and pressing __Ctrl+/__ again. This may seem a bit silly, but quickly commenting sections of code is a great way to test different scenarios while not deleting code entirely. (We will explore this further in a later lesson.)
The draw function
Guess what the second __function definition__ called *draw()* does. Yeah, it *draws* stuff on the canvas, usually 60 times a second.

We will demonstrate that in a bit, but for now, let’s focus on the __body__ of *draw()*, the part in the curly braces. We see exactly one __function__ being called inside draw(). One guess what it does?

Catching on to the naming scheme? This __function__ fills the __background__ with a color of our choice. And our choice is `220`, apparently. I don’t really care for this choice. Let’s try a smaller number, like `24`.

That’s dark. Can we get darker? Try `0`.

Can we get even darker? Try `-100000000000000000` just in case. 

It was worth a shot, but `-100000000000000000` is no darker than `0`. By the same token `100000000000000000` is no lighter than `255`. 

There are exactly 256 possible values (`1` through `255` plus one more for `0`) for this __parameter__. Anything bigger gets constrained to `255`, anything smaller to `0`. And with only one value, it’s always black, white, or grey.

But what if we put three values in there separated by commas?

That’s a nice sky blue there. Did you try different values? What happens if all three values are the same? What happens if two values are `0` and the other `255` and vice versa? 

Paint By Number
Maybe you have seen Hex values on the web, something that looked like this: `#64c8fa`. Kind of weird. Why are numbers cavorting with letters like that 🤭

Hex is actually short for *hexadecimal* which is just a hoity-toity way of saying sixteen (literally *six and ten*). Each digit can have one of sixteen values, so with two digits, you can have 16 times 16 values, which is 256. `#64c8fa` is *64*, *c8*, *fa*, which is `100`, `200`, `250`, which are the __RGB values__.

Why RGB? If we look at a typical pixel in a typical screen, it has a red subpixel, a green subpixel, and a blue subpixel — R, G, and B.
Source: Wikimedia Commons

There’s another parameter we can add called *alpha*, which tells us the opacity. I like to think of opacity as how well a layer blocks the layer behind it from being seen. The higher the number, the less visible the next layer. The __background__ with all the *nesses*.

`background(brightness)`
`background(brightness, opaqueness)`
`background(redness, greenness, blueness)`
`background(redness, greenness, blueness, opaqueness)`
Getting into Shape
The background isn’t the only thing we can color. There are two more __functions__ that we can call with those same __parameter lists__: *fill()* and *stroke()*. But to use them, we need a shape.

We will start with the simplest of shapes: The humble circle. Go ahead and place `circle(200,200,200);` on line 8.
We see that the default color for __fill__ is white while the default for __stroke__ is black. Before we use our knowledge of how to change the colors, why don’t we change the thickness of the stroke. Put `strokeWeight(10);` on line 9.
That’s nice and thick. Now call *stroke()* and *fill()* with the colors of your choice. This example shows a sunny yellow and a muted orange.
Now that we have different parts of the object displaying, what happens if we change the __alpha__ to `160` by adding it to the __parameter list__ for __stroke__?

See how both the background and fill colors bleed through the stroke? What happens if you do the same for *fill()*? For *background()*?

Now try setting __alpha__ for the background, stroke, and fill to `8`.

Notice how it fades in over time? That is each layer being drawn over the last but never quite being able to completely block what came before.

And for our last trick, let’s prevent p5.js from looping at all. In *setup()*, put `noLoop();` in line 3. Before you click *run*, what do you think will happen?

Now run it and see.

*What!?* Why did *that* happen? We will return to this question in the next lesson…
Time to Tinker
You have learned quite a bit in this lesson. Before moving on, we encourage you to experiment. You may want to comment out *noLoop()* using __Ctrl+/__ ( __Cmd+/__ ).

Can you make more than one circle? Try copying and pasting the *circle()* and changing the values in the __parameter list__. Can you make the circles different colors, with different thickness of the stroke? Can you arrange the circles into a flower shape maybe with somewhat transparent petals? Can you place a small circle in the center of a large, opaque one and still see it? Can you make something that looks like the Moon?




