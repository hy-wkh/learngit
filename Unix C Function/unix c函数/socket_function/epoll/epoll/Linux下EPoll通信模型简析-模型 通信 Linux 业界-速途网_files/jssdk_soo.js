var shareme;
var urls = window.location.href;


//判断jquery是否引入
// if(typeof jQuery == 'undefined'){
//   var fileref=document.createElement('script')//创建标签
//   fileref.setAttribute("type","text/javascript")//定义属性type的值为text/javascript
//   fileref.setAttribute("src", "http://mp.vmeti.com/jssdk/jquery-1.8.3.min.js")//文件的地址
//   document.getElementsByTagName("head")[0].appendChild(fileref);
// } 

if(isWeiXin()){
  var weifileref=document.createElement('script')//创建标签
  weifileref.setAttribute("type","text/javascript")//定义属性type的值为text/javascript
  weifileref.setAttribute("src", "http://res.wx.qq.com/open/js/jweixin-1.0.0.js")//文件的地址
  document.getElementsByTagName("head")[0].appendChild(weifileref);
}


function isWeiXin(){
  var ua = window.navigator.userAgent.toLowerCase();
  if(ua.match(/MicroMessenger/i) == 'micromessenger'){
    return true;
  }else{
    return false;
  }
}

//修改jq  
//$(window).load(function(){ 
$(function(){
 if(isWeiXin()){
      $.ajax({
        type: "POST",
        async: false,   //同步请求
        url: "http://www.sootoo.com/wxagent/",
        data:{
            urls:urls,
            callback:'callback'
        },
        //dataType: 'json',
        success:function(data){
          shareme = eval(data);
          
          wx.config({
              debug: false,
              appId: shareme.appId,
              timestamp: shareme.timestamp,
              nonceStr: shareme.nonceStr,
              signature: shareme.signature,
              jsApiList: [
              // 所有要调用的 API 都要加到这个列表中
              'checkJsApi',
              'onMenuShareTimeline',
              'onMenuShareAppMessage',
              'onMenuShareQQ',
              'onMenuShareWeibo',
              'hideMenuItems',
              'showMenuItems',
              'hideAllNonBaseMenuItem',
              'showAllNonBaseMenuItem',
            ]
          });
          
          wx.ready(function () {
            //判断当前版本是否支持指定 JS 接口，支持批量判断
              wx.checkJsApi({ 
                  jsApiList: [
                    'getNetworkType',
                    'previewImage',
                    'onMenuShareTimeline',
                    'onMenuShareAppMessage'
                  ],
                  success: function (res) {
                    
                  },
                  fail:function(){
                    //alert('抱歉您的微信版本有问题不支持分享功能！');
                  }
              });

            //分享接口
            //监听“分享给朋友”
             wx.onMenuShareAppMessage({
                title: '',
                desc: '',
                link: '',
                imgUrl: '',
                trigger: function (res) {
                  alert('用户点击发送给朋友');
                },
                success: function (res) {
                  alert('已分享');
                },
                cancel: function (res) {
                  alert('已取消');
                },
                fail: function (res) {
                  alert(JSON.stringify(res));
                }
              });
             

            // 监听“分享到朋友圈”按钮点击
            wx.onMenuShareTimeline({
                title: '',
                link: '',
                imgUrl: '',
                trigger: function (res) {
                  alert('用户点击分享到朋友圈');
                },
                success: function (res) {
                  alert('已分享');
                },
                cancel: function (res) {
                  alert('已取消');
                },
                fail: function (res) {
                  alert(JSON.stringify(res));
                }
              });

            var wchat_title = $("#wchat_title").html();
            var wchat_desc = $("#wchat_desc").html();
            var wchat_link = $("#wchat_link").html();
            var wchat_imgUrl = $("#wchat_imgUrl").html();

            var shareData = {
              title:wchat_title,
              desc: wchat_desc,
              link: wchat_link,
              imgUrl: wchat_imgUrl
            };


            wx.onMenuShareAppMessage(shareData);
            wx.onMenuShareTimeline(shareData);

            });

            wx.error(function (res) {
              alert(res.errMsg);
            }); 
        },
        error: function () {
         
        },
    });
  }else{
      //alert("对不起您不在微信浏览器中，不支持分享功能！");
      return false;
  }

});


