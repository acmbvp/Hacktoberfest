import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:http/http.dart';
import 'package:polls_app/screens/SearchScreen.dart';
import 'package:polls_app/screens/addpoll.dart';
import 'package:polls_app/screens/response.dart';
import 'package:polls_app/screens/resultpage.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.green,
        visualDensity: VisualDensity.adaptivePlatformDensity,
        canvasColor: Colors.white,
      ),
      home: MyHomePage(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class MyHomePage extends StatefulWidget {
  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  List allPolls;
  String initValue="Choose One";
  TextEditingController _textcontroller = TextEditingController();
  ScrollController controller = ScrollController();
  bool closeTopContainer = false;
  double topContainer = 0;

  Future<void> getPolls() async{
    String url="http://anirudh1998.pythonanywhere.com/pollapp/getpolls";
    Response response = await get(url);
    List result=jsonDecode(response.body);
    setState(() {
      allPolls=result.reversed.toList();
    });

  }


  Future<Map> getPollDetail({id}) async{
    String url="http://anirudh1998.pythonanywhere.com/pollapp/getpolldetails/$id/";
    Response response = await get(url);
    Map result=jsonDecode(response.body);
    print(result);
    return result;
  }



  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    _textcontroller=TextEditingController();
    controller.addListener(() {

      double value = controller.offset/119;

      setState(() {
        topContainer = value;
        closeTopContainer = controller.offset > 50;
      });
    });
    getPolls();
  }


  @override
  void dispose() {
    // TODO: implement dispose
    super.dispose();
    _textcontroller.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.green,
      body: CustomScrollView(
        slivers: [
          SliverAppBar(
            title: Text("Poll It",style: GoogleFonts.poppins(fontWeight: FontWeight.w500,fontSize: 22),),
            leading: Icon(Icons.change_history),
            centerTitle: true,
            pinned: true,
            elevation: 0,
            actions: [
              IconButton(
                onPressed: () {
                  Navigator.of(context).push(
                    MaterialPageRoute(
                      builder: (context) => AddPollScreen()
                    ),
                  );
                },
                icon: Icon(Icons.add,size: 30,),
              ),
            ],
          ),
          SliverList(
            delegate: SliverChildListDelegate(
              [
                AnimatedContainer(
                  duration: Duration(milliseconds: 200),
                  curve: Curves.easeIn,
                  height: closeTopContainer?0:150,
                  child: Padding(
                    padding: EdgeInsets.only(left: 10,right: 10,top: 10,bottom: 10),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Flexible(child: Text("Search for Polls",style: GoogleFonts.poppins(color: Colors.white,fontSize: 25,fontWeight: FontWeight.w500),)),
                        Flexible(child: SizedBox(height: 10,)),
                        Flexible(
                          child: Container(
                            decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(2),
                            ),
                            child: TextFormField(
                              controller: _textcontroller,
                              cursorColor: Colors.green,
                              style: GoogleFonts.poppins(),
                              decoration: InputDecoration(
                                  contentPadding: EdgeInsets.only(left: 5),
                                  hintText: "Enter The Invite Code",
                                  hintStyle: GoogleFonts.poppins(),
                              ),
                              onFieldSubmitted: (id) async{
                                Map res=await getPollDetail(id: id);
                                if(res!=null) {
                                  Navigator.of(context).push(MaterialPageRoute(
                                    builder: (context) => SearchScreen(result: res,)
                                  ));
                                }
                              },
                            ),
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
                Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    AnimatedContainer(
                        duration: Duration(milliseconds:100),
                        height: 50,
                        padding: EdgeInsets.only(left: 10),
                        child: Text("Recent Polls",style: GoogleFonts.poppins(color: Colors.white,fontSize: 25,fontWeight: FontWeight.w500),)),
                    RefreshIndicator(
                      onRefresh: getPolls,
                      child: Container(
                        height: 840,
                        decoration: BoxDecoration(
                          color: Colors.green,
                          borderRadius: BorderRadius.vertical(top: Radius.circular(4)),
                        ),
                        child: allPolls==null?Center(
                          child: CircularProgressIndicator(backgroundColor: Colors.white,),
                        ):ListView.builder(
                          controller: controller,
                          itemCount: allPolls.length,
                          itemBuilder: (context,i) {
                            return Container(
                              padding: EdgeInsets.only(top: 20,bottom: 30),
                              decoration: BoxDecoration(
                                color: Colors.white,
                                borderRadius: BorderRadius.circular(7),
                              ),
                              margin: EdgeInsets.only(bottom: 20,left: 8,right: 8),
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Padding(
                                    padding: const EdgeInsets.only(top: 5,left: 8),
                                    child: Text(allPolls[i]['id'].toString()+". "+allPolls[i]['pollQuestion'],style: GoogleFonts.poppins(fontSize: 17),),
                                  ),
                                  Padding(
                                    padding: const EdgeInsets.only(top: 5,left: 8),
                                    child: Row(
                                      children: [
                                        RaisedButton(
                                          color: Colors.amber,
                                          onPressed: () {
                                            Navigator.of(context).push(
                                              MaterialPageRoute(
                                                builder: (context) => ResponseScreen(option_a: allPolls[i]['option_1'],option_b: allPolls[i]['option_2'],option_c: allPolls[i]['option_3'],option_d: allPolls[i]['option_4'],poll_id: allPolls[i]['id'],poll: allPolls[i]['pollQuestion'],)
                                              )
                                            );
                                          },
                                          child: Text("Respond",style: GoogleFonts.poppins(fontSize: 15,color: Colors.white,fontWeight: FontWeight.w600),),
                                        ),
                                        SizedBox(width: 10,),
                                        RaisedButton(
                                          color: Colors.green,
                                          onPressed: () {
                                            Navigator.of(context).push(
                                                MaterialPageRoute(
                                                    builder: (context) => ResultsPage(poll_id: allPolls[i]['id'])
                                                )
                                            );
                                          },
                                          child: Text("Results",style: GoogleFonts.poppins(fontSize: 15,color: Colors.white,fontWeight: FontWeight.w600),),
                                        ),
                                      ],
                                    ),
                                  ),
                                ],
                              ),
                            );
                          },
                        ),
                      ),
                    ),
                  ],
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}
