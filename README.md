# Darts

An old game I started back when I was in college as a freshmen.  The first implementation was written in python.  Since then I've re-written it in java and now C++.  It was originally named darts because I started out with the intention of making a game where the user had to dodge lawn darts.  For the uninitiated, [this](https://en.wikipedia.org/wiki/Lawn_darts) is lawn darts.  But with my vast reserves of freetime to find readily available images for a lawn darts themed game, this is what I landed on.  This was my first time trying out the SFML library.

# How to build

The same way you would build any project with cmake:

```bash
mkdir build && cd build && cmake ../ && cmake --build . && ./darts
```

# Design choices

The decision to define an abstract class for the sprites will make it easier to handle sf::Sprites.  Especially when making the game more complex by having it rain down more than one coconut.

I chose to define an abstract class for the buttons because it was a good use case for the DRY principle.
