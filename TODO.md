# To Do


### Gifts
the logic for adding more gifts are mostly in the game manager

```cpp

void GameManager::HandleTheCollision()
{
	m_currBoard.handleObjectCollision();//if something happend

	//check special status of the robot
	if (m_currBoard.getHideGiftStatus())
	{
		m_currBoard.HideSingleGuard();
		
	}
	//if m_CurrBoard.getFreezeGiftStatus -- check from the robot!!! if he ate a freeze gift
	/*
	* m_currBoard.Freeze()  ---- change all guards speed to 0; DONT FORGET TO TIME AND return their speed to default values
	
	*/
	// if he ate a time 
	// m_currBoard.Add Time,  - maybe manager can do it alone

	// if he ate life
	// life++;
	


	m_currBoard.updateGuards(); // will go over guard, and delete if neeeded

	
	m_currBoard.updateGifts();
	
	
}
```

dont forget to add the neccsary double dispatch calls, check the current implmention of hide gift

1. Freeze gift.
2. Life gift.
3. Time gift.


### Player can die from bombs
the player should recive -- life if he collides with a bomb  explosion.
same logic as guards, just instead of removing from vector life.

### Score
add some score


### Finish Game
if the player have 0 lifes what happends???
on the other side, what happend if you finished the last stage???


#### Bonus
some basic sounds
better ui - buttons, hover
pause button
restart button


