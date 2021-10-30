exports.run = async (client, message) => {
    message.channel.send({
        embed: {
            color: 'RANDOM',
            footer: { text: 'Thanks ❤' },
            fields: [
                { name: 'Do you want to invite me to your server?', value: '[click here to invite me !!](https://discord.com/oauth2/authorize?client_id=781167576792563753&scope=bot&permissions=66584384)'},
            ]
        },
    });

};
