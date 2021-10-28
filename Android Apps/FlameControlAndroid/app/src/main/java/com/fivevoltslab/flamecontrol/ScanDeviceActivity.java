package com.fivevoltslab.flamecontrol;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.bluetooth.le.BluetoothLeScanner;
import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanResult;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Set;

import static androidx.recyclerview.widget.DividerItemDecoration.VERTICAL;

public class ScanDeviceActivity extends AppCompatActivity {

    private BluetoothAdapter mBluetoothAdapter;
    public static final String TAG = "ScanDeviceActivity";

    List<BluetoothDevice> deviceList;
    private static final long SCAN_PERIOD = 3000; //scanning for 4.5 seconds
    private Handler mHandler;

    public static RecyclerView availableDeviceRecyclerView;
    public static RecyclerView pairedDeviceRecyclerView;

    private TextView scanningTextView;
    BluetoothLeScanner bluetoothLeScanner;

    DeviceAdapter availableDeviceAdapter;
    DeviceAdapter pairedDeviceAdapter;

    Set<BluetoothDevice> pairedDevicesSet;
    ArrayList<BluetoothDevice> pairedDevicesArrayList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scan_device);

        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
        }

        Log.d(TAG, "onCreate");
        availableDeviceRecyclerView = findViewById(R.id.availableDeviceRecyclerView);
        pairedDeviceRecyclerView = findViewById(R.id.pairedDevicesRecyclerView);

        scanningTextView = findViewById(R.id.scanningTextView);

        FloatingActionButton scanAgainFab = findViewById(R.id.scanAgainFloatingActionButton);
        scanAgainFab.setOnClickListener(view -> populateAvailableDevicesRecView());

        mHandler = new Handler();
        if (!getPackageManager().hasSystemFeature(PackageManager.FEATURE_BLUETOOTH_LE)) {
            Toast.makeText(this, R.string.ble_not_supported, Toast.LENGTH_SHORT).show();
            finish();
        }

        final BluetoothManager bluetoothManager =
                (BluetoothManager) getSystemService(Context.BLUETOOTH_SERVICE);
        mBluetoothAdapter = bluetoothManager.getAdapter();

        bluetoothLeScanner = mBluetoothAdapter.getBluetoothLeScanner();

        // Checks if Bluetooth is supported on the device.
        if (mBluetoothAdapter == null) {
            Toast.makeText(this, R.string.ble_not_supported, Toast.LENGTH_SHORT).show();
            finish();
            return;
        }


        populateAvailableDevicesRecView();
        populatePairedDevicesRecView();
    }

    @Override
    public boolean onSupportNavigateUp() {
        scanLeDevice(false);
        mHandler.removeCallbacksAndMessages(null);
        finish();
        return true;
    }

    @Override
    public void onBackPressed() {
        scanLeDevice(false);
        mHandler.removeCallbacksAndMessages(null);
        finish();
    }

    private void populateAvailableDevicesRecView() {
        deviceList = new ArrayList<>();
        scanLeDevice(true);

    }

    private void populatePairedDevicesRecView() {
        pairedDevicesArrayList = new ArrayList<>();


        if (mBluetoothAdapter != null) {
            pairedDevicesSet = mBluetoothAdapter.getBondedDevices();

            if (pairedDevicesSet.size() > 0) {
                pairedDevicesArrayList.addAll(pairedDevicesSet);
                RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(this);
                pairedDeviceRecyclerView.setLayoutManager(layoutManager);
                pairedDeviceAdapter = new DeviceAdapter(pairedDevicesArrayList, this, position -> {

                    BluetoothDevice device = pairedDevicesArrayList.get(position);
                    bluetoothLeScanner.stopScan(mLeScanCallback);
                    Bundle b = new Bundle();
                    b.putString(BluetoothDevice.EXTRA_DEVICE, pairedDevicesArrayList.get(position).getAddress());
                    Intent result = new Intent();
                    result.putExtras(b);
                    setResult(Activity.RESULT_OK, result);
                    finish();

                });
                pairedDeviceRecyclerView.setLayoutManager(layoutManager);
                pairedDeviceRecyclerView.setAdapter(pairedDeviceAdapter);
                DividerItemDecoration decoration = new DividerItemDecoration(getApplicationContext(), VERTICAL);
                decoration.setDrawable(Objects.requireNonNull(getResources().getDrawable(R.drawable.divider)));
                pairedDeviceRecyclerView.addItemDecoration(decoration);

            }

        }
    }

    private void scanLeDevice(final boolean enable) {
        if (enable) {
            // Stops scanning after a pre-defined scan period.
            mHandler.postDelayed(() -> {
                bluetoothLeScanner.stopScan(mLeScanCallback);

                if (deviceList.isEmpty()) {
                    Toast.makeText(ScanDeviceActivity.this, "No Devices Found!", Toast.LENGTH_LONG).show();
                    scanningTextView.setText("No Bluetooth devices were found.");
                } else {
                    scanningTextView.setText(deviceList.size() + " Bluetooth device has been found.");
                }
                RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(this);
                availableDeviceRecyclerView.setLayoutManager(layoutManager);
                availableDeviceAdapter = new DeviceAdapter(deviceList, this, position -> {

                    BluetoothDevice device = deviceList.get(position);
                    bluetoothLeScanner.stopScan(mLeScanCallback);
                    Bundle b = new Bundle();
                    b.putString(BluetoothDevice.EXTRA_DEVICE, deviceList.get(position).getAddress());
                    Intent result = new Intent();
                    result.putExtras(b);
                    setResult(Activity.RESULT_OK, result);
                    finish();

                });
                availableDeviceRecyclerView.setLayoutManager(layoutManager);
                availableDeviceRecyclerView.setAdapter(availableDeviceAdapter);
                DividerItemDecoration decoration = new DividerItemDecoration(getApplicationContext(), VERTICAL);
                decoration.setDrawable(Objects.requireNonNull(getResources().getDrawable(R.drawable.divider)));
                availableDeviceRecyclerView.addItemDecoration(decoration);


            }, SCAN_PERIOD);

            bluetoothLeScanner.startScan(mLeScanCallback);
            scanningTextView.setText("Scanning for Bluetooth devices...");
        } else {
            bluetoothLeScanner.stopScan(mLeScanCallback);
        }

    }


    private final ScanCallback mLeScanCallback = new ScanCallback() {
        @Override
        public void onScanResult(int callbackType, ScanResult result) {
            addDevice(result.getDevice(), result.getRssi());

            super.onScanResult(callbackType, result);
        }

        @Override
        public void onBatchScanResults(List<ScanResult> results) {
            super.onBatchScanResults(results);
        }

        @Override
        public void onScanFailed(int errorCode) {
            super.onScanFailed(errorCode);
        }
    };

    private void addDevice(BluetoothDevice device, int rssi) {
        boolean deviceFound = false;

        for (BluetoothDevice listDev : deviceList) {
            if (listDev.getAddress().equals(device.getAddress())) {
                deviceFound = true;
                break;
            }
        }


        if (!deviceFound) {
            deviceList.add(device);

        }
    }

    @Override
    public void onStart() {
        super.onStart();

        IntentFilter filter = new IntentFilter(BluetoothDevice.ACTION_FOUND);
        filter.addAction(BluetoothAdapter.ACTION_DISCOVERY_FINISHED);
        filter.addAction(BluetoothAdapter.ACTION_STATE_CHANGED);
    }

    @Override
    public void onStop() {
        super.onStop();
        bluetoothLeScanner.stopScan(mLeScanCallback);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        bluetoothLeScanner.stopScan(mLeScanCallback);
    }

    protected void onPause() {
        super.onPause();
        scanLeDevice(false);
    }
}
