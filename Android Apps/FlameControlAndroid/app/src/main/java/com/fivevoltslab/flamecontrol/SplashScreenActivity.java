package com.fivevoltslab.flamecontrol;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.LinearInterpolator;
import android.widget.ImageView;

public class SplashScreenActivity extends AppCompatActivity {

    ImageView splashImageView;
    Animation animation;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash_screen);

        splashImageView = findViewById(R.id.splashImageView);
        animation = new AlphaAnimation(1, 0); //to change visibility from visible to invisible
        animation.setDuration(1200); //1.2 second duration for each animation cycle
        animation.setInterpolator(new LinearInterpolator());
        animation.setRepeatCount(Animation.INFINITE); //repeating indefinitely
        animation.setRepeatMode(Animation.REVERSE); //animation will start from end point once ended.
        splashImageView.startAnimation(animation);

        Handler handler = new Handler();

        int splashTime = 2500;
        handler.postDelayed(this::goToMainActivity, splashTime);
    }

    private void goToMainActivity() {
        animation.cancel();
        startActivity(new Intent(SplashScreenActivity.this, MainActivity.class));
        finish();
    }
}
