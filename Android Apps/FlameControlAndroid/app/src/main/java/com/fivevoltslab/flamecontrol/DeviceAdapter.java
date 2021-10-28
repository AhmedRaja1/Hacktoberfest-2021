package com.fivevoltslab.flamecontrol;

import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;


/**
 * Created by Hammad.
 */
public class DeviceAdapter extends RecyclerView.Adapter<RecyclerView.ViewHolder> {

    private final List<BluetoothDevice> dataSet;
    Context mContext;
    int total_types;
    private final OnClickListenerScanDevice onClickListener;

    public static class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        TextView deviceNameTextView, macAddressTextView;
        OnClickListenerScanDevice onClickListener;

        public ViewHolder(View itemView, OnClickListenerScanDevice onClickListener) {
            super(itemView);
            this.deviceNameTextView = itemView.findViewById(R.id.deviceNameTextView);
            this.macAddressTextView = itemView.findViewById(R.id.macAddressTextView);
            this.onClickListener = onClickListener;
            itemView.setOnClickListener(this);
        }

        @Override
        public void onClick(View view) {
            onClickListener.onItemClick(getAdapterPosition());
        }
    }


    public DeviceAdapter(List<BluetoothDevice> data, Context context, OnClickListenerScanDevice onClickListener) {
        this.dataSet = data;
        this.mContext = context;
        this.onClickListener = onClickListener;
        total_types = dataSet.size();
    }

    @NonNull
    @Override
    public RecyclerView.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.device_adapter_layout,
                parent, false);
        return new ViewHolder(v, onClickListener);
    }

    @Override
    public void onBindViewHolder(final RecyclerView.ViewHolder holder, final int listPosition) {

        String name = dataSet.get(listPosition).getName();
        if (name == null) {
            name = "No Name";
        }
        ((ViewHolder) holder).deviceNameTextView.setText(name);
        ((ViewHolder) holder).macAddressTextView.setText(dataSet.get(listPosition).getAddress());

    }

    @Override
    public int getItemCount() {
        return dataSet.size();
    }

    public interface OnClickListenerScanDevice {
        void onItemClick(int position);
    }
}
