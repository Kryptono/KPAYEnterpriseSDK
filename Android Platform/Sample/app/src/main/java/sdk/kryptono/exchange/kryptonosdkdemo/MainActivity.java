package sdk.kryptono.exchange.kryptonosdkdemo;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.TextView;

import java.math.BigDecimal;

import sdk.kryptono.exchange.kryptonoexchangesdk.model.kryptono.KryptonoSdkData;
import sdk.kryptono.exchange.kryptonoexchangesdk.model.kryptono.KryptonoSdkSettings;
import sdk.kryptono.exchange.kryptonoexchangesdk.mvp_module.kryptono.KryptonoExchangeActivity;
import sdk.kryptono.exchange.kryptonoexchangesdk.mvp_module.kryptono.KryptonoExchangeFragment;

public class MainActivity extends AppCompatActivity
{
    public static final String CLIENT_KEY_PROD = "eyJhbGciOiJIUzUxMiJ9.eyJjcmVhdGVkQXQiOjE1MzMyODcxMDQwNDgsInN1YiI6IiIsImVudGVycHJpc2VJRCI6ImQxZTMwNjRhLWIwZDAtNGJhNy1hYWI1LTZiYTI4ZGFhYmYzOSIsInR5cGUiOiJjbGllbnRLZXkiLCJleHAiOjE3MzA5Mzc2MDAwLCJpYXQiOjE1MzMyODcxMDR9.Li8Lrl5gFPs3dglAxIPfBNrAVaSsnkRkrdPxqW1jD8XroGOXAxvpt2bwO6Qu8zMVaYbPOX8RuS84cTDlXltLyQ";
    public static final String CHECKSUM_KEY_PROD = "Zt3m+PbKotYSZQrdGw5d2KeD3f5eM447GTCkbBHujbw=";
    public static final String IDENTITY_ID_PROD = "ThangPM_Prod";

    public static final int REQUEST_CODE_KRYPTONO_EXCHANGE_SDK = 999;

    TextView tvPaymentId;
    TextView tvErrorMessage;
    RelativeLayout rlChangeSDKLanguage;
    RelativeLayout rlOpenSDK;
    EditText etFixedAmount;

    private AlertDialog.Builder alertDialog;

    private KryptonoSdkSettings sdkSettings;
    private KryptonoSdkSettings.Language language = KryptonoSdkSettings.Language.ENGLISH;

    private int languageSelectedIdx = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        tvPaymentId = (TextView) findViewById(R.id.tv_payment_id);
        tvErrorMessage = (TextView) findViewById(R.id.tv_error_message);
        etFixedAmount = (EditText) findViewById(R.id.et_fixed_amount);
        rlChangeSDKLanguage = (RelativeLayout) findViewById(R.id.rl_change_sdk_language);
        rlOpenSDK = (RelativeLayout) findViewById(R.id.rl_open_sdk);

        /*
            Author: ThangPM
            Date:   16-08-2018
            Title:  DEMO Language Selection
         */
        final CharSequence[] languages = new CharSequence[] {"English", "Simplified Chinese"};
        rlChangeSDKLanguage.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                alertDialog = new AlertDialog.Builder(MainActivity.this);
                alertDialog.setSingleChoiceItems(languages, languageSelectedIdx, new DialogInterface.OnClickListener()
                {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i)
                    {
                        if (languages[i].equals("English"))
                        {
                            language = KryptonoSdkSettings.Language.ENGLISH;
                            languageSelectedIdx = 0;
                        }
                        else
                        {
                            language = KryptonoSdkSettings.Language.CHINESE;
                            languageSelectedIdx = 1;
                        }
                    }
                });
                alertDialog.setTitle(getString(R.string.language_selection_title));
                alertDialog.setPositiveButton("OK", null);
                alertDialog.show();
            }
        });

        rlOpenSDK.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                tvPaymentId.setText(" --/--");
                tvErrorMessage.setText(" --/--");

                /*
                    IMPORTANT: Initialize required parameters for Kryptono Exchange SDK.

                    Author:     ThangPM
                    Date:       16-08-2018
                    Message:

                    - We will provide you the CLIENT and CHECKSUM keys for initializing SDK settings.
                    - Please pass your users' indentities to our SDK as String format.
                    - We have also provide language selection. If you want to use, please set your desire language before starting SDK.
                    - Last but not least, we provide you 2 modes:
                        + Normal mode: User can input their desire amount for transfering, exchanging and buying with credit card.
                        + Fixed mode: User cannot input, you need to pass the amount as string format to SDK settings before starting SDK.

                    P/s: Please contact our support or document for more detail about these 2 modes.
                 */

                sdkSettings = new KryptonoSdkSettings(CLIENT_KEY_PROD, CHECKSUM_KEY_PROD, IDENTITY_ID_PROD);
                sdkSettings.setLanguage(language);

                String fixedAmount = etFixedAmount.getText().toString();
                if (!fixedAmount.equals(""))
                    sdkSettings.setFixedAmount(new BigDecimal(fixedAmount));

                Intent intent = new Intent(MainActivity.this, KryptonoExchangeActivity.class);
                intent.putExtra(KryptonoExchangeFragment.ARGUMENT_SDK_SETTINGS, sdkSettings);
                startActivityForResult(intent, REQUEST_CODE_KRYPTONO_EXCHANGE_SDK);
            }
        });
    }

    /*
        IMPORTANT: Receive response data from Kryptono Exchange SDK.

        Author:     ThangPM
        Date:       16-08-2018
        Message:

        - Whenever the transaction are processed, we will return to your application the ID of payment (paymentId)
        - If there is a critical error, the SDK will be forced stop and the error code will be return here.
        - Please check the following error codes:

            KRYPTONO_SDK_NO_ERROR_CODE                  -> Nothing happen. This is when users click back button from the main screen of SDK.
            KRYPTONO_SDK_SETTINGS_NOT_CONFIGURED        -> This is due to SDK's settings are not setup yet.
            KRYPTONO_SDK_INVALID_CLIENT_KEY             -> The client key you are using is invalid. Please check with our team support.
            KRYPTONO_SDK_INVALID_CHECKSUM_KEY           -> The checksum key you are using is invalid. Please check with our team support.
            KRYPTONO_SDK_INVALID_ACCESS_TOKEN           -> Users failed to authorize themself. Please tell them to sign in to our SDK again.
            KRYPTONO_SDK_WRONG_CLIENT_KEY_TYPE          -> We usually provide you server and client keys. Be careful of using them.
            KRYPTONO_SDK_ENTERPRISE_ACCOUNT_NOT_FOUND   -> We cannot find your enterprise information due to wrong client key. Please use another one.
    */
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data)
    {
        if (requestCode == REQUEST_CODE_KRYPTONO_EXCHANGE_SDK)
        {
            if (resultCode == Activity.RESULT_OK)
            {
                KryptonoSdkData kryptonoSdkData = (KryptonoSdkData) data.getExtras().get(KryptonoExchangeFragment.KRYPTONO_SDK_RETURN_DATA);
                if (kryptonoSdkData != null)
                {
                    if (kryptonoSdkData.getPaymentId() != null && !kryptonoSdkData.getPaymentId().equals(""))
                    {
                        tvPaymentId.setText(kryptonoSdkData.getPaymentId());
                    }
                    else if (kryptonoSdkData.getErrorCode() != null)
                    {
                        tvErrorMessage.setText(kryptonoSdkData.getErrorCode().getMessageResId());
                    }
                }
            }
        }

        super.onActivityResult(requestCode, resultCode, data);
    }
}