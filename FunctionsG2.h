bool CollisionDetecitionG2(int ob1_left_x, int ob1_right_x, int ob1_up_y, int ob1_down_y,
int ob2_left_x, int ob2_right_x, int ob2_up_y, int ob2_down_y)
        {
            bool colision =
                     ob2_right_x >= ob1_left_x &&
                     ob2_left_x <= ob1_right_x &&
                     ob1_up_y <= ob2_down_y &&
                     ob1_down_y >= ob2_up_y; 
            return colision;

        }