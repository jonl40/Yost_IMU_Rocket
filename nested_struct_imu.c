

//Component: Yost 3-Space™ LX Embedded part number TSS-LX
#include <stdio.h>

    typedef struct{ //initialize struct
    float pitch;
    float yaw;
    float roll;
    }euler_angles;

    typedef struct{
    float x;
    float y;
    float z;
    }accel;

    typedef struct{
    euler_angles e_orient;
    accel r_accel;
    }yost_imu; // user defined data type

void update_yost(yost_imu *); // pointer to struct

void main(){
    // random numbers for imu read sensor data here to initialize struct
    yost_imu rocket = {{1.2,3.4,5.6},{9.8,21.0,5.56}};
    printf("Before update_yost euler angle pitch: %f\n",rocket.e_orient.pitch);
    printf("Before update_yost euler angle yaw: %f\n",rocket.e_orient.yaw);
    printf("Before update_yost euler angle roll: %f\n\n",rocket.e_orient.roll);

    printf("Before update_yost accel x: %f\n",rocket.r_accel.x);
    printf("Before update_yost accel y: %f\n",rocket.r_accel.y);
    printf("Before update_yost accel z: %f\n\n\n",rocket.r_accel.z);

    update_yost(&rocket); // function call pass memory address of rocket

    printf("After update_yost euler angle pitch: %f\n",rocket.e_orient.pitch);
    printf("After update_yost euler angle yaw: %f\n",rocket.e_orient.yaw);
    printf("After update_yost euler angle roll: %f\n\n",rocket.e_orient.roll);

    printf("After update_yost accel x: %f\n",rocket.r_accel.x);
    printf("After update_yost accel y: %f\n",rocket.r_accel.y);
    printf("After update_yost accel z: %f\n\n\n",rocket.r_accel.z);
}

// for sensor just read the sensor data
void update_yost(yost_imu *imu_ptr){ // point to memory address (get contents of mem address)
  imu_ptr->e_orient.pitch = 99.5; // point (imu_ptr) to e_orient and access the pitch filed
  imu_ptr->e_orient.yaw = 12349;
  imu_ptr->e_orient.roll = 49;

  imu_ptr->r_accel.x = 55; // point (imu_ptr) to e_orient and access the pitch filed
  imu_ptr->r_accel.y = 66;
  imu_ptr->r_accel.z = 77;
}
