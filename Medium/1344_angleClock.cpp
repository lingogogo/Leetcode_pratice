double angleClock(int hour, int minutes) {
    // The count of angle start from 12 o'clock
    
    // first, count the minutes angle;
    double min_angle = minutes * 6.0;

    // second, count the hour;
    double hour_angle = (minutes/60.0+ hour) * 30;
    // printf("h:%f, m:%f\n",hour_angle,min_angle);
    double output = min_angle>hour_angle? min_angle - hour_angle : hour_angle - min_angle;
    if(output>180) output = 360 - output;
    return output;

}
