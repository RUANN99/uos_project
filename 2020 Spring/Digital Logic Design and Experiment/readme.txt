Final project

Goal: To implement the “drawing tool” with the Hack assembly language.
(demo video: https://web.microsoftstream.com/video/239b0c91-8017-4fc8-a89d-3e2f545b558c)

Requirements:
1. Draw a 32 × 16 grid on the screen. (columns × rows)
  – The width of the grid line is 1 pixel.
  – The size of each cell is 16 × 16 (including the grid line).
2. Draw a 16 × 16 cursor at the (16, 8) position. (column,row)
  – (0, 0) position is the top-left corner.
  – You can choose any fancy shape for the cursor (except solid black box).
3. When an arrow key (up/down/left/right) is pressed, the cursor moves to the adjacent cell in that direction and the previous position is colored in black.
  – If might be tricky to handle the key press, since you may get lots of consecutive “key pressing” events even when you press a key very shortly. To handle this issue, when a key is pressed, you have to “wait” until the key is released and then proceed to handle the key event.
  – The cursor is not allowed to move outside the screen.
4. Checklist
  – Did you succeed to draw the grid lines?
  – Did you succeed to draw the cursor?
  – Did you succeed to move the cursor when an arrow key is pressed?
  – Did you succeed to draw black cells along the cursor movement?
  – Did you succeed to prevent the cursor moving out of the screen area?
