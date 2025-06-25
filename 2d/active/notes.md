# Active Development 
### Additional notes
- [link to website for sound](https://www.bfxr.net/)
## bird 7 The Collision Update

bird7 (“The Collision Update”)
bird7 introduces collision detection, pausing the game when a collision occurs.
Important Code
The pausing of the game is handled by toggling a local boolean variable scrolling (checked in love.update(dt)) upon collision detection.
The collision detection itself is handled within our Bird class (it’s essentially the same AABB Collision Detection algorithm we saw last week), but with some leeway in order to give the user a little more leniency.
  function Bird:collides(pipe)
      if (self.x + 2) + (self.width - 4) >= pipe.x and self.x + 2 <= pipe.x + PIPE_WIDTH then
          if (self.y + 2) + (self.height - 4) >= pipe.y and self.y + 2 <= pipe.y + PIPE_HEIGHT then
              return true
          end
      end

      return false
  end

## bird 6 The PipePair Update

bird6 spawns the Pipe sprites in “pairs”, with one Pipe facing up and the other facing down.



Important Code
Previously, in bird5, we were only worried about spawning individual Pipes, so having a simple Pipe class sufficed. However, now that we want to spawn pairs of Pipes, it makes sense to create a PipePair class to tackle this problem.
  PipePair = Class{}

  local GAP_HEIGHT = 90

  function PipePair:init(y)
      self.x = VIRTUAL_WIDTH + 32
      self.y = y

      self.pipes = {
          ['upper'] = Pipe('top', self.y),
          ['lower'] = Pipe('bottom', self.y + PIPE_HEIGHT + GAP_HEIGHT)
      }

      self.remove = false
  end

  function PipePair:update(dt)
      if self.x > -PIPE_WIDTH then
          self.x = self.x - PIPE_SPEED * dt
          self.pipes['lower'].x = self.x
          self.pipes['upper'].x = self.x
      else
          self.remove = true
      end
  end

  function PipePair:render()
      for k, pipe in pairs(self.pipes) do
          pipe:render()
      end
  end
The result of having a PipePair class is that we replace a lot of our previous Pipe logic in main.lua with analogous PipePair logic. The implications of this are that the flow of our main.lua file need not change drastically, but with the caveat that now we need to accommodate for PipePairs rather than individual Pipes.
In our case, we can mimic the Pipe class to an extent, as long as we provide logic for ensuring a reasonable gap height between the Pipes, as well as accurate y values for our sprites, since we will be mirroring the top Pipe. Be sure to read carefully through the changes in main.lua, paying close attention to the comments!


## bird 5 Infinite Pipe Update

bird5 adds the Pipe sprite to our game, rendering it an “infinite” number of times.
Important Code
Unsurprisingly, we create our Pipe sprite by modeling it with a Pipe class.
Inside this class, we create an init method that spawns a pipe at a random vertical position at the rightmost edge and within the lower quarter of the screen. We also create an update method that “scrolls” the Pipe to the left of the screen based on its previous position, a negative scroll value, and its dt. Lastly, we include functionality for rendering the Pipe to the screen:
  Pipe = Class{}
  local PIPE_IMAGE = love.graphics.newImage('pipe.png')
  local PIPE_SCROLL = -60

  function Pipe:init()
      self.x = VIRTUAL_WIDTH
      self.y = math.random(VIRTUAL_HEIGHT / 4, VIRTUAL_HEIGHT - 10)
      self.width = PIPE_IMAGE:getWidth()
  end

  function Pipe:update(dt)
      self.x = self.x + PIPE_SCROLL * dt
  end

  function Pipe:render()
      love.graphics.draw(PIPE_IMAGE, math.floor(self.x + 0.5), math.floor(self.y))
  end
It’s notable to mention that we are never creating multiple Pipe sprites. Rather, we are always re-rendering the same Pipe sprite we created in line 15. This helps us save memory while accomplishing the same goal.

We also make use of a spawnTimer value which we create in main.lua order to determine how often to spawn a new Pipe on the screen:
  local spawnTimer = 0
And then, in love.update():
  spawnTimer = spawnTimer + dt

  if spawnTimer > 2 then
      table.insert(pipes, Pipe())
      print('Added new pipe!')
      spawnTimer = 0
  end
  ...
  for k, pipe in pairs(pipes) do
      pipe:update(dt)

      if pipe.x < -pipe.width then
          table.remove(pipes, k)
      end
  end
We spawn a new pipe every two seconds, and remove it from the table once it’s no longer visible past the left edge of the screen.

Finally, in love.draw(), we call the render function of each pipe currently in the table:
  for k, pipe in pairs(pipes) do
      pipe:render()
  end








bird5 adds the Pipe sprite to our game, rendering it an “infinite” number of times.
Important Code
Unsurprisingly, we create our Pipe sprite by modeling it with a Pipe class.
Inside this class, we create an init method that spawns a pipe at a random vertical position at the rightmost edge and within the lower quarter of the screen. We also create an update method that “scrolls” the Pipe to the left of the screen based on its previous position, a negative scroll value, and its dt. Lastly, we include functionality for rendering the Pipe to the screen:
  Pipe = Class{}
  local PIPE_IMAGE = love.graphics.newImage('pipe.png')
  local PIPE_SCROLL = -60

  function Pipe:init()
      self.x = VIRTUAL_WIDTH
      self.y = math.random(VIRTUAL_HEIGHT / 4, VIRTUAL_HEIGHT - 10)
      self.width = PIPE_IMAGE:getWidth()
  end

  function Pipe:update(dt)
      self.x = self.x + PIPE_SCROLL * dt
  end

  function Pipe:render()
      love.graphics.draw(PIPE_IMAGE, math.floor(self.x + 0.5), math.floor(self.y))
  end
It’s notable to mention that we are never creating multiple Pipe sprites. Rather, we are always re-rendering the same Pipe sprite we created in line 15. This helps us save memory while accomplishing the same goal.

We also make use of a spawnTimer value which we create in main.lua order to determine how often to spawn a new Pipe on the screen:
  local spawnTimer = 0
And then, in love.update():
  spawnTimer = spawnTimer + dt

  if spawnTimer > 2 then
      table.insert(pipes, Pipe())
      print('Added new pipe!')
      spawnTimer = 0
  end
  ...
  for k, pipe in pairs(pipes) do
      pipe:update(dt)

      if pipe.x < -pipe.width then
          table.remove(pipes, k)
      end
  end
We spawn a new pipe every two seconds, and remove it from the table once it’s no longer visible past the left edge of the screen.

Finally, in love.draw(), we call the render function of each pipe currently in the table:
  for k, pipe in pairs(pipes) do
      pipe:render()
  end
bird6 (“The PipePair Update”)
bird6 spawns the Pipe sprites in “pairs”, with one Pipe facing up and the other facing down.



bird8 (“The State Machine Update”)
bird8 modularizes our code as a State Machine:



While our eventual goal is the above, this update lays the foundations with the following states: BaseState, TitleScreenState, and PlayState.

Important Code
We manage all our game states using an overarching StateMachine module, which handles the logic for initializing and transitioning between them.
The TitleScreenState will transition to the PlayState via keyboard input. The BaseState is a skeleton for the other states- it defines empty methods and passes them on via inheritance.
Of particular note in main.lua is the creation of our gStateMachine table to hold function calls to our different states:
  ...
  require 'StateMachine'
  require 'states/BaseState'
  require 'states/PlayState'
  require 'states/TitleScreenState'
  ...
  function love.load()
  ...
  gStateMachine = StateMachine {
      ['title'] = function() return TitleScreenState() end,
      ['play'] = function() return PlayState() end,
      ['score'] = function() return ScoreState() end
  }
  gStateMachine:change('title')
  ...
  end
By representing our game states as modules, we vastly simplify the logic in our main.lua file. Now, each major part of our code will be in its own module, and each state can be accessed through our global state machine table.

Be sure to read carefully through the new modules, paying close attention to the comments, to understand how our main.lua has been simplified so cleanly! You should see that the PlayState should contain much of the logic previously in main.lua.
bird9 (“The Score Update”)
bird9 introduces a new state, ScoreState, to help keep track of the score.
Important Code
Once a collision is detected, the PlayState will transition to the ScoreState, which will display the user’s final score and transition back to the PlayState if the “enter” key is pressed. Note our addition to the PlayState:update() function to implement this transition logic:
  for k, pair in pairs(self.pipePairs) do
      for l, pipe in pairs(pair.pipes) do
          if self.bird:collides(pipe) then
              gStateMachine:change('score', {
                  score = self.score
              })
          end
      end
  end

  if self.bird.y > VIRTUAL_HEIGHT - 15 then
      gStateMachine:change('score', {
          score = self.score
      })
  end
The score itself is also tracked in PlayState:update() by incrementing a score counter each time the bird flies successfully through a PipePair.
  for k, pair in pairs(self.pipePairs) do
      if not pair.scored then
          if pair.x + PIPE_WIDTH < self.bird.x then
              self.score = self.score + 1
              pair.scored = true
          end
      end

      pair:update(dt)
  end
Logic for displaying the score to the screen during the PlayState is added to the PlayState:render() function:
  function PlayState:render()
  ...
  love.graphics.setFont(flappyFont)
  love.graphics.print('Score: ' .. tostring(self.score), 8, 8)
  ...
  end
The ScoreState itself is implemented as an additional module with logical implementations for the empty methods in BaseState:
  ScoreState = Class{__includes = BaseState}

  function ScoreState:enter(params)
      self.score = params.score
  end

  function ScoreState:update(dt)
      if love.keyboard.wasPressed('enter') or love.keyboard.wasPressed('return') then
          gStateMachine:change('play')
      end
  end

  function ScoreState:render()
      love.graphics.setFont(flappyFont)
      love.graphics.printf('Oof! You lost!', 0, 64, VIRTUAL_WIDTH, 'center')
      love.graphics.setFont(mediumFont)
      love.graphics.printf('Score: ' .. tostring(self.score), 0, 100, VIRTUAL_WIDTH, 'center')
      love.graphics.printf('Press Enter to Play Again!', 0, 160, VIRTUAL_WIDTH, 'center')
  end
bird10 (“The Countdown Update”)
bird10 introduces yet another state, CountdownState, whose purpose is to give the user time to get ready before being thrust into the game.
Important Code
First, we add CountdownState to our global state machine in main.lua:
  ...
  require 'states/CountdownState'
  ...
  function love.load()
  ...
  gStateMachine = StateMachine {
      ...
      ['countdown'] = function() return CountdownState() end,
      ...
  }
  ...
  end
The CountdownState is implemented as another module and it merely displays a 3-second countdown on the screen before play begins:
  CountdownState = Class{__includes = BaseState}

  COUNTDOWN_TIME = 0.75

  function CountdownState:init()
      self.count = 3
      self.timer = 0
  end

  function CountdownState:update(dt)
      self.timer = self.timer + dt

      if self.timer > COUNTDOWN_TIME then
          self.timer = self.timer % COUNTDOWN_TIME
          self.count = self.count - 1

          if self.count == 0 then
              gStateMachine:change('play')
          end
      end
  end

  function CountdownState:render()
      love.graphics.setFont(hugeFont)
      love.graphics.printf(tostring(self.count), 0, 120, VIRTUAL_WIDTH, 'center')
  end
As such, we modify our code in TitleScreenState.lua such that TitleScreenState transitions to CountdownState rather than directly to PlayState.
Then, in CountdownState.lua we transition to PlayState once the countdown reaches 0.
In PlayState.lua, we ensure that upon collision, we transition to ScoreState.
Finally, in ScoreState.lua, we transition back to CountdownState on keyboard input.
bird11 (“The Audio Update”)
bird11 adds some music and sound effects to the game
Important Code
We initialize a sounds table in love.load(), taking care to include the sound files we reference in our project directory, then set the music sound to loop indefinitely and begin playing it:
  sounds = {
      ['jump'] = love.audio.newSource('jump.wav', 'static'),
      ['explosion'] = love.audio.newSource('explosion.wav', 'static'),
      ['hurt'] = love.audio.newSource('hurt.wav', 'static'),
      ['score'] = love.audio.newSource('score.wav', 'static'),
      ['music'] = love.audio.newSource('marios_way.mp3', 'static')
  }

  sounds['music']:setLooping(true)
  sounds['music']:play()
Lastly, we play the remaining sound effects in the PlayState module (jumps, score increases, collisions, etc.).
bird12 (“The Mouse Update”)
bird12 adds mouse interactivity to the game in order to more closely resemble the original Flappy Bird iOS game.
This update is left as an at-home exercise, but do take note of the following important function:
love.mousepressed(x, y, button)
This function is a callback fired by LÖVE2D every time a mouse button is pressed; it also gives us the (x, y) of where the mouse cursor was at the time of the button press.
If stuck on this exercise, feel free to open up bird12 to take a look at the implementation details. Be sure to read the comments carefully!