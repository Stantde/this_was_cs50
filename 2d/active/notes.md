# Active Development 
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

