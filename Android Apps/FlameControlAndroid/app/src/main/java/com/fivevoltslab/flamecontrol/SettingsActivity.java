package com.fivevoltslab.flamecontrol;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.preference.Preference;
import androidx.preference.PreferenceFragmentCompat;

public class SettingsActivity extends AppCompatActivity {
    private static SettingsActivity instance = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.settings_activity);
        getSupportFragmentManager()
                .beginTransaction()
                .replace(R.id.settings, new SettingsFragment())
                .commit();
        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
        }

        this.instance = this;
    }

    public static SettingsActivity getInstance() {
        return instance;
    }


    @Override
    public boolean onSupportNavigateUp() {
        finish();
        return true;
    }


    public static class SettingsFragment extends PreferenceFragmentCompat {
        @Override
        public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
            setPreferencesFromResource(R.xml.root_preferences, rootKey);
        }

        @Override
        public boolean onPreferenceTreeClick(Preference preference) {
            String key = preference.getKey();
            if (key.equals(getString(R.string.preference_about))) {
                showAbout(SettingsActivity.getInstance());
            }

            return false;
        }
    }


    public static void showAbout(Activity activity) {
        // Inflate the about message contents
        View messageView = activity.getLayoutInflater().inflate(R.layout.about_layout, null, false);

        // When linking text, force to always use default color. This works
        // around a pressed color state bug.

        if (SettingsActivity.getInstance() != null) {
            AlertDialog.Builder builder = new AlertDialog.Builder(SettingsActivity.getInstance());
            builder.setIcon(R.drawable.about_icon);
            builder.setTitle("About");
            builder.setView(messageView);
            builder.create();
            builder.show();
        }
    }
}