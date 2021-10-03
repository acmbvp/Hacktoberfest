const express = require('express')
const app = express();
// Stream Chat server SDK
const StreamChat = require('stream-chat').StreamChat;

app.use(express.static((__dirname + '/public')))
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

const serverClient = new StreamChat(
    '6newfzcbjmku', 
    'x5yrjzyqv96f4jevdf33ncggtf43zjgr4cndh8y2dnut59zb3jcnppsska7pxymn'
);

app.get('/token', (req, res) => {
    const { username } = req.query

    if (username) {
        const token = serverClient.createToken(username)
        res.status(200).json({ token, status: "sucess" })
    } else {
        res.status(401).json({ message: "invalid request", status: "error" })
    }
});

app.post('/updateUser', async (req, res) => {
    const { userID } = req.body

    if (userID) {
        const updateResponse = await serverClient.updateUsers([{ 
            id: userID, 
            role: 'admin'
         }]);
    
        res.status(200).json({ user: updateResponse, status: "sucess" })
    } else {
        res.status(401).json({ message: "invalid request", status: "error" })
    }
});

app.get('/', (req, res) => {
    res.sendFile("/index.html")
});

app.listen(8800, () => {
    console.log('Example app listening on port 8800!')
});