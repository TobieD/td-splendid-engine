# Event System

Basis for the windows in the engine


Application --send events --> Layers

Window (class)
    - Mouse move
    - Resize
    - ..

Window should be created by Application but window should not be aware of Application
Window class will receive window callback and create a custom event

Custom Event (class)
- Press a button -> Trigger MouseButtonPressed Event

## Layers

TBD